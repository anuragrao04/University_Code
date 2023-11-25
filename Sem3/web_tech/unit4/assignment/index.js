// Add Expres
const express = require("express");
const bodyParser = require("body-parser");
const { MongoClient, ServerApiVersion } = require("mongodb");

// Initialize Express
const app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Create a MongoClient with a MongoClientOptions object to set the Stable API version
require("dotenv").config();
const uri = process.env.MONGODB_URI; // get mongodb URI from .env file

console.log(uri);

const client = new MongoClient(uri, {
  serverApi: {
    version: ServerApiVersion.v1,
    strict: true,
    deprecationErrors: true,
  },
});

client.connect();
const dbName = "BangaloreCity";
const collectionName = "restaurants";

const database = client.db(dbName);
const collection = database.collection(collectionName);

app.post("/create_restaurant", async (req, res) => {
  const restaurant = req.body; // this will be a json with the restaurant info
  try {
    const result = await collection.insertOne(restaurant);
    res.sendStatus(200); // 200 OK
  } catch (e) {
    res.sendStatus(500); // 500 internal server error
    console.log(e);
  }
});

app.get("/get_all_restaurants", async (req, res) => {
  try {
    const result = await collection.find({}).toArray();
    res.json(result);
  } catch (e) {
    res.sendStatus(500);
    console.log(e);
  }
});

app.post("/update_grade", async (req, res) => {
  const restaurant_id = req.body.restaurant_id;
  const grade = req.body.grade;
  try {
    const result = await collection.updateOne(
      { rest_id: restaurant_id },
      { $set: { rest_reviews: grade } },
    );
    res.sendStatus(200);
  } catch (e) {
    res.sendStatus(500);
    console.log(e);
  }
});

app.post("/delete_restaurant", async (req, res) => {
  const restaurantid = req.body.restaurant_id;
  try {
    const result = await collection.deleteOne({ rest_id: restaurantid });
    res.sendStatus(200);
  } catch (e) {
    res.sendStatus(500);
    console.log(e);
  }
});

app.get("/", (req, res) => {
  res.send("You've reached the API for Bangalore City Restaurants.");
});

// Initialize server
app.listen(6000, () => {
  console.log("Running on port 6000.");
});
