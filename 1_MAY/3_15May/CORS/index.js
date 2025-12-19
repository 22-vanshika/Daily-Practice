// CROSS ORIGIN RESOURSE SHARING -- shouldn't be allowed by default
const cors=require("cors");
const express=require("express");
const app=express();

app.use(cors());