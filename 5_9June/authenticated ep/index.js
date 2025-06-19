const express = require ("express")
const app = express();

app.use(express.json());

let users=[];
// Stateful token --- tokken getting stored in a variable/ database

// problem is that we need to SEND A REQUEST TO THE DATABASE EVERYTIME  the user wants to hit an 
// AUTHENTICATED ENDPOINT

function getToken(){
    let options = [ 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n'
        , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'x' , 'y' , 'z' , '0' , '1' , '2' , '3'
        , '4' , '5' , '6' , '7' , '8' , '9' , 'A' ]

        let token="";
        for(let i=0;i<15;i++){
            token += options[Math.floor(Math.random() * options.length)];
        }

        return token;
}

app.post("/signIn", function(req,res){
    let username = req.body.username;
    let password = req.body.password;

    users.push({
        username : username,
        password : password
    })

    res.json({
        message : "you are signed In!"
    })

    console.log(users)
})

app.post("/signUp", function(req,res){
    let username = req.body.username;
    let password = req.body.password;

    // let foundUser = NULL;
    // for(let i=0;i<users.length;i++){
    //     if(users[i].username==username && users[i].password==password){
    //         foundUser = users[i];
    //     }
    // }

    let foundUser = users.find(function(u){
        if(u.username==username && u.password==password) return true;
        else return false;
    })
    if(foundUser){
        const token = getToken();
        foundUser.token = token;
        res.json({
            message : token
        })
    }
    else {
        res.status(403).send({
            message:"Invalid username or password"
        })
    }
    console.log(users)
    
})

app.get("/me",function(req,res){
    const token = req.headers.token;
    let foundUser=users.find(function(u){
        if(u.token==token) return true;
        else return false;
    });

    console.log(users)
    if(foundUser){
        res.json({
            foundUser : foundUser
        })
    }

})

app.listen(3000);
