// JWTs are Stateless**: JWTs contain all the information needed to authenticate a request, 
// so the server doesn’t need to store session data. All the `data` is stored in the token itself.

const express = require ("express")
const app = express();
const jwt = require("jsonwebtoken");
const jwt_secret = "randomText";

app.use(express.json());

let users=[];   // acting as db

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

    let foundUser = users.find(function(u){
        if(u.username==username && u.password==password) return true;
        else return false;
    })
    if(foundUser){
       // const token = getToken();  
       const token = jwt.sign({
        username : username 
       },jwt_secret)  


        // foundUser.token = token;
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
    const token = req.headers.token; //jwt

    // db roundtrip not required for username  --- roundtrip saved
    const decodedInformation = jwt.verify(token,jwt_secret);// {username : "vanshika"}
    const username = decodedInformation.username

    // db trip req for getting info , such as courses and all
    let foundUser=users.find(function(u){
        if(u.username==username) return true;
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