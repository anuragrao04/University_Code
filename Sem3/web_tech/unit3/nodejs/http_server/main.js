const http = require("http");
let counter = 0;
const server = http.createServer((req, res) => {
  res.writeHead(200, {
    "Content-Type": "text/plain",
  });
  res.end("Hello World!");
  console.log(req);
});

server.listen(3000, () => {
  console.log("localhost:3000");
});
