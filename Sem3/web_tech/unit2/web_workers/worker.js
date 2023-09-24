self.onmessage = function(event) {
  console.log("got message from main thread: " + event.data);
  self.postMessage("Hello! This is worker. got your message!");
}

