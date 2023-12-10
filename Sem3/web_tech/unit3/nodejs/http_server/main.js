const http = require("http");
let counter = 0;

const server = http.createServer((req, res) => {
  res.writeHead(200, {
    "Content-Type": "text/plain",
  });
  counter += 1;
  res.end(`Hello World! This site has been visited ${counter} times`);
  console.log(req);
});

server.listen(3000, () => {
  console.log("localhost:3000");
});
