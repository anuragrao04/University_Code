let getWeather = new Promise((resolve, reject) => {
  // assume that the weather is good and the API returns true
  let niceWeather = true;
  if (niceWeather) {
    resolve(true);
  }
  else {
    reject("Bad weather :(");
  }
});

let getIcecreamPlace = new Promise((resolve, reject) => {
  // this would also come from an API. Assuming that the API returns the nearest icecream place now
  let nearest_icecream_place = {
    name: "Naturals Icecreams",
    distance: 5,
  }
  nearest_icecream_place = null;

  if (nearest_icecream_place) {
    resolve(nearest_icecream_place);
  } else {
    reject("Icecream Place Not Found :(")
  }
});


let getBooking = new Promise((resolve, reject) => {
  // your booking confirmation will also come from an external API. Assuming you got a booking here
  let booking = {
    name1: "Anurag",
    name2: "Cupcake",
    time: "1600",
  };


  if (booking) {
    resolve(booking);
  }
  else {
    reject("Got no booking :(")
  }
});




let icecream_date = getWeather
  .then((weather) => {
    console.log("Weather is nice!")
    return getIcecreamPlace;
  })
  .then((IcecreamPlace) => {
    console.log("Got icecream place!");
    console.log(IcecreamPlace);
    return getBooking
  })
  .then((booking) => {
    console.log("Got booking!");
    console.log(booking);
  })
  .catch((error) => {
    console.log(error);
  }
  );

