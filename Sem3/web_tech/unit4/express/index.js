const express = require("express");
const app = express();

app.use(express.json());

app.post("/login", (req, res) => {
  const username = req.body.username;
  const password = req.body.password;
  console.log(username);
  console.log(password);
  res.send("login done");
});

// /getFriends/:userId/abc/:ungabunga

app.get("/getFriends/:userId/abc/:ungabunga", (req, response) => {
  const userId = req.params.userId;
  const ungabunga = req.params.ungabunga;
  response.send("User id: " + userId + " and unga bunga: " + ungabunga);
});

app.listen(6969, () => {
  console.log("Server is running on port 6969");
});
