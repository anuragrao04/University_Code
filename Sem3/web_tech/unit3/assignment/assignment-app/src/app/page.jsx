"use client";
import { useState, useEffect } from "react";

export default function Home() {
  const styles = {
    card: {
      border: "1px solid black",
      padding: "1rem",
      margin: "1rem",
    },
    button: {
      backgroundColor: "grey",
      color: "white",
      padding: "5px",
      margin: "5px",
      borderRadius: "0.5rem",
      border: "none",
      cursor: "pointer",
      minHeight: "25px",
      minWidth: "25px",
    },
    quan_titty: { display: "inline", paddingRight: "10px" },
  };

  let [items, setItems] = useState([
    {
      key: 0,
      name: "Dell Vostro 7500",
      description:
        "15.6-inch FHD (1920 x 1080) Anti-glare LED Backlight Non-touch Narrow Border WVA Display",
      price: 82000,
      quantity: 0,
    },
    {
      key: 1,
      name: "Macbook Air M1",
      description: "Don't buy this laptop, worse decision ever",
      price: 92000,
      quantity: 0,
    },
    {
      key: 2,
      name: "HP Laptop",
      description: "Also don't buy this",
      price: 10000,
      quantity: 0,
    },
  ]);

  const [total, setTotal] = useState(0);

  const today = new Date();

  const dd = String(today.getDate()).padStart(2, "0");
  const mm = String(today.getMonth() + 1).padStart(2, "0");
  const yyyy = String(today.getFullYear()).padStart(2, "0");

  const formattedToday = `${dd}/${mm}/${yyyy}`;

  const delivery = new Date(today.setDate(today.getDate() + 3));

  const ddd = String(delivery.getDate()).padStart(2, "0");
  const mmd = String(delivery.getMonth() + 1).padStart(2, "0");
  const yyyyd = String(delivery.getFullYear()).padStart(2, "0");

  const formattedDelivery = `${ddd}/${mmd}/${yyyyd}`;

  const addQuantity = (key) => {
    let newItems = [...items];
    newItems[key].quantity++;
    setItems(newItems);
  };

  const subQuantity = (key) => {
    let newItems = [...items];
    newItems[key].quantity > 0
      ? newItems[key].quantity--
      : (newItems[key].quantity = 0);
    setItems(newItems);
  };

  useEffect(() => {
    let total = 0;
    items.forEach((item) => {
      total += item.price * item.quantity;
    });
    setTotal(total);
  }, [items]);

  return (
    <main>
      <h1>Order Summary</h1>
      {items.map((item) => (
        <div style={styles.card} key={item.key}>
          <h2>{item.name}</h2>
          <p>{item.description}</p>
          <p>Price: {item.price}</p>
          <p style={styles.quan_titty}>Quantity: {item.quantity}</p>
          <button style={styles.button} onClick={() => addQuantity(item.key)}>
            +
          </button>
          <button style={styles.button} onClick={() => subQuantity(item.key)}>
            -
          </button>
        </div>
      ))}

      <h3>Total: {total}</h3>
      <h4>Date: {formattedToday}</h4>
      <h4>Delivery Date: {formattedDelivery}</h4>
    </main>
  );
}
