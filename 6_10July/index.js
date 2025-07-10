const express = require("express");
const app = express();

app.use(express.json());
app.get("/multiply", function (req, res) {
    const a = parseInt(req.query.a);
    const b = parseInt(req.query.b);

  let c = a * b;
  res.status(200).json({
    message: c,
  });
});
app.get("/sum", function (req, res) {
    const a = parseInt(req.query.a);
    const b = parseInt(req.query.b);

  let c = a + b;
  res.status(200).json({
    message: c,
  });
});
app.get("/divide", function (req, res) {
    const a = parseInt(req.query.a);
    const b = parseInt(req.query.b);

  let c = a / b;
  res.status(200).json({
    message: c,
  });
});
app.get("/substract", function (req, res) {
    const a = parseInt(req.query.a);
    const b = parseInt(req.query.b);

  let c = a - b;
  res.status(200).json({
    message: c,
  });
});

app.listen(3000);
