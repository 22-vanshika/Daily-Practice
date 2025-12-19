const express = require('express');
const app = express();

function idOldEnoughMiddleware(req,res,next){
  const age = req.query.age;
  if(age>14){
    next();
  }
  else{
    res.json({
      msg:"Sorry you are not of age yet"
    })
  }
}
// IF YOU WANT ALL THE REQUEST TO HAVE THE MIDDLEWARE below this line only ✅
// app.use(idOldEnoughMiddleware);

app.get('/ride1',idOldEnoughMiddleware ,function(req,res){
  res.json({
    msg : "You have enjoyed ride1"
  });
});

app.get('/ride2',idOldEnoughMiddleware ,function(req,res){
  res.json({
    msg : "You have enjoyed ride2"
  });
});

// app.use(idOldEnoughMiddleware); --------- ❌ useless here

app.listen(3000)