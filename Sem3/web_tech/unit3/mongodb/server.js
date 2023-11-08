import * as url from "url";
import * as http from "http";
import fs from "fs";
import * as mongodb from "mongodb";

http.createServer(function(req, res) {
  let pathname = url.parse(req.url).pathname;
  console.log("Request for " + pathname + " received.");
  if (request.method === "GET") {
    console.log("Executing Mongo DB");
    mongodb.MongoClient.connect(
      "mongodb://localhost:27017/",
      function(err, db) { },
      function(err, client) {
        if (err) throw err;
        var db = client.db("mydb");
        db.collection("customers")
          .find({})
          .toArray(function(err, result) {
            if (err) throw err;
            console.log(result);
            res.writeHead(200, { "Content-Type": "text/html" });
            res.write(JSON.stringify(result));
            res.end();
            client.close();
          });
      },
    );
  } else if (request.metthod === "POST") {
    console.log("Executing Mongo DB");
    mongodb.MongoClient.connect(
      "mongodb://localhost:27017/",
      function(err, db) { },
      function(err, client) {
        if (err) throw err;
        var db = client.db("mydb");
        db.collection("customers")
          .insertOne({ name: "Company Inc", address: "Highway 37" })
          .toArray(function(err, result) {
            if (err) throw err;
            console.log(result);
            res.writeHead(200, { "Content-Type": "text/html" });
            res.write(JSON.stringify(result));
            res.end();
            client.close();
          });
      },
    );
  }
});
