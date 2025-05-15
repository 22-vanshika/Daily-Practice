const express = require ("express");
const app = express();

function middlewareLogger(req,res,next){
    console.log("Method is " + req.method);
    console.log("Host is " + req.host);
    console.log("Host Name is " + req.hostname);
    console.log(new Date());
    next();
}

app.use(middlewareLogger);

app.get('/sum', function(req,res){
    const a = parseInt(req.query.a);
    const b = parseInt(req.query.b);
    res.json({
        ans: a+b,
    })
});


app.listen(3000);


// OUTPUT
// Method is GET
// Host is localhost:3000
// Host Name is localhost
// 2025-05-15T11:33:41.438Z