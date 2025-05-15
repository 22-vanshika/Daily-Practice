const express = require("express");
const app=express();

// in express if you want to send json data to the post api, 
// you need to first parse the json data and then send 

// sounds like the work of middleware -- modifying the request or response object
// use express.json() -- middleware

app.use(express.json());

// why is it required to call this  and not use like other middleware 
// ----eg. app.use(logger)
// because it return another function

// let middleware=express.json();
// app.use(middleware);

// body-parser library can also be used, express library under the hood uses this library only
 // const bodyParser = require("body-parser")
 // app.use(bodyParser.json());

app.post('/',(req,res)=>{
    console.log(req.body) // will give a error ❌ -- undefined
    const a=req.body.a;
    res.json({a});
})