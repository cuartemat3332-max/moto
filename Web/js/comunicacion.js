let esp32 = "http://moto.local/datos";

async function traerDatos() {
  try {
    let respuesta = await fetch(esp32);
    let objetoDatos = await respuesta.json();
    console.log("Valor del sensor:", objetoDatos.sensor);
    console.log("Estado:", objetoDatos.estado);

  } catch (error) {
    console.error("No se pudo conectar con el ESP32:", error);
  }
}

setInterval(traerDatos, 1500);
