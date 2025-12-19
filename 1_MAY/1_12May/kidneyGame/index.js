// creating an http server
const express = require("express"); // assign builder
const app = express(); // builder build hospital

// in memory database(not recommended but just for practice)
const users = [
  {
    user: "Vanshika",
    kidneys: [
      {
        healthy: true,
      },
      {
        healthy: false,
      },
      {
        healthy: false,
      },
    ],
  },
];

app.get("/", function (req, res) {
  let healthyKidneys = 0;
  let unhealthyKidneys = 0;
  let totalKidneys = users[0].kidneys.length;
  for (var i = 0; i < totalKidneys; i++) {
    if (users[0].kidneys[i].healthy) {
      healthyKidneys = healthyKidneys + 1;
    }
  }
  unhealthyKidneys = totalKidneys - healthyKidneys;
  res.send({
    totalKidneys,
    healthyKidneys,
    unhealthyKidneys,
  });
});

app.use(express.json());

app.post("/", function (req, res) {
  const isHealthy = req.body.isHealthy;
  console.log(req.body);
  users[0].kidneys.push({
    healthy: isHealthy,
  });
  res.json({
    msg: "done",
  });
});

app.put("/", function (req, res) {
  let totalKidneys = users[0].kidneys.length;
  for (var i = 0; i < totalKidneys; i++) {
    if (!users[0].kidneys[i].healthy) users[0].kidneys[i].healthy = true;
  }
  res.send({
    msg: "updated",
  });
});


// app.delete("/", function (req, res) {
//   const hasUnhealthy = users[0].kidneys.some(kidney => !kidney.healthy);
//   if (hasUnhealthy) {
//     users[0].kidneys = users[0].kidneys.filter(kidney => kidney.healthy);
//     res.send({ msg: "deleted unhealthy kidneys" });
//   } else {
//     res.status(411).json({ msg: "You have no bad kidneys" });
//   }
// });


app.delete("/", function (req, res) {

  if (unhealthyKidneysCheck()) { 
    let totalKidneys = users[0].kidneys.length;
    const newKidneys = [];
    for (var i = 0; i < totalKidneys; i++) {
      if (users[0].kidneys[i].healthy) {
        newKidneys.push({
          healthy: true,
        });
      }
    }
    users[0].kidneys = newKidneys;
    res.send({
      msg: "deleted unhealthy kidneys",
    });
  } else {
    res.status(411).json({
      msg: "You have no bad kidneys",
    });
  }
});

function unhealthyKidneysCheck() {
  let totalKidneys = users[0].kidneys.length;
  for (var i = 0; i < totalKidneys; i++) {
    if (!users[0].kidneys[i].healthy) return true; // unhealthy kidney found
  }
  return false; // no unhealthy kidney found
}

app.listen(3000); // hospital's address
