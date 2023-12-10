const url = require("url");
const myUrl = "http://localhost:3000/somePath?name=John&age=30";

const parsedUrl = url.parse(myUrl);

console.log(parsedUrl);
console.log(parsedUrl.query.name);
console.log(parsedUrl.query.age);
console.log(parsedUrl.host);
console.log(parsedUrl.pathname);
console.log(parsedUrl.protocol);
console.log(parsedUrl.port);
console.log(parsedUrl.search);
console.log(parsedUrl.href);
