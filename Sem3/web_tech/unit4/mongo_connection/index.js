const mongo = require("mongodb");
const MongoClient = mongo.MongoClient;

const url = "mongodb://localhost:27017";

// MongoClient.connect(url).then((client) => {
//   const db = client.db("test");
//   db.collection("testCollection")
//     .find()
//     .toArray()
//     .then((result) => console.log(result));
// });

const connectToDb = async () => {
  const client = await MongoClient.connect(url);
  const db = client.db("test");
  const result = await db
    .collection("testCollection")
    .deleteOne({ age: { $gt: 15 } });
  console.log(result);
};

connectToDb();
