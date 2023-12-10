const fs = require("fs");

fs.writeFileSync("test.txt", "Hello world", (err, bytes) => {
  if (err) throw err;
  console.log("Written");
});

fs.readFileSync("test.txt", "utf-8", (err, data) => {
  if (err) {
    console.log("Error: ", err);
  } else {
    console.log(data);
  }
});

fs.unlinkSync("test.txt", (err) => {
  if (err) {
    console.log("error: ", err);
  } else {
    console.log("File deleted successfully!");
  }
});
