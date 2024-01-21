let productos = 100;
let id = ["A0001", "A0002", "A0003", "A0004", "A0005", "A0006", "A0007"];
let Name = ["Ibuprofeno", "Meloxicam", "Clonazepam", "Mebucaina ", "Lemonflu", "Aspirina", "Paracetamol"];
let price = [6.50, 4.40, 3.25, 4.00, 2.30, 1.75, 3.50];
let quantity = [60, 55, 40, 56, 30, 70, 80];
let choice, casos;
let total, cantidad;
const prompt = require(`prompt-sync`)();
do {
    console.log("\n1. Agregar producto\n");
    console.log("2. Quitar producto\n");
    console.log("3. Mostrar inventario\n");
    console.log("4. calcular precio del producto\n");
    console.log("5.quitar o agregar stock\n");
    console.log("6. Salir\n");
    console.log("Ingrese su eleccion: ");
    choice = parseInt(prompt("Ingrese su eleccion: ") || "0");

    switch (choice) {
        case 1:
            Agregar();
            break;
        case 2:
            Quitar();
            break;
        case 3:
            Mostrar();
            break;
        case 4:
            Precio();
            break;
        case 5:
            Stock();
            break;

        case 6:
            console.log("Saliendo del programa.\n");
            break;
        default:
            console.log("Opción no válida. Inténtelo de nuevo.\n");
    }
} while (choice != 6);

function Agregar() {
    if (id.length < productos) {
        console.log(`Ingrese detalles del producto:`);
        id[id.length] = prompt("ID:") || "";
        Name[Name.length] = prompt("Nombre") || "";
        price[price.length] = parseFloat(prompt("Precio:") || "0");
        quantity[quantity.length] = parseFloat(prompt("Cantidad:") || "0");
    }
    else {
        console.log("El inventario está lleno. No se pueden agregar más productos.\n");
    }
}

function Quitar() {
    if (id.length > 0) {
        console.log("Ingrese el ID del producto a quitar:\n ");
        let removeId = prompt("") || "";
        let found = false;
        for (let i = 0; i < id.length; ++i) {
            if (id[i] === removeId) {
                found = true;
                id.splice(i, 1);
                Name.splice(i, 1);
                price.splice(i, 1);
                quantity.splice(i, 1);
                console.log("Producto eliminado exitosamente.\n");
                break;
            }
        }

        if (!found) {
            console.log("Producto no encontrado.\n");
        }
    }
    else {
        console.log("El inventario está vacío. No hay productos para quitar.\n");
    }
}
function Mostrar() {

    console.log(" id: \t medicamentos:\t precios:\t cantidad:\t ");
    for (let i = 0; i < id.length; i++) {
        console.log(`${id[i]} \t ${Name[i]} \t${price[i]} \t ${quantity[i]}"\t`);
    }
}

function Precio() {

    console.log(" id \t medicamentos\n");
    for (let i = 0; i < id.length; i++) {
        console.log(id[i], "\t", Name[i]);
    }
    console.log("Ingrese el ID del producto a comprar: \n");

    let Id2 = prompt("") || "";

    let found = false;
    for (let i = 0; i < id.length; ++i) {
        if (id[i] === Id2) {
            found = true;
            console.log(`Ingrese la cantidad de ${Name[i]} que deseas adquirir (quedan ${quantity[i]} disponibles)`);
            cantidad = parseFloat(prompt("") || "0");

            quantity[i] -= cantidad;
            if (quantity[i] < 0) {
                do {
                    quantity[i] += cantidad;
                    console.log("No existe suficiente stock");
                    console.log(`Ingrese la cantidad de ${Name[i]} que deseas adquirir (quedan ${quantity[i]} disponibles)`);
                    cantidad = parseFloat(prompt("") || "0");
                    quantity[i] -= cantidad;
                } while (quantity[i] < 0);
            }
            total = price[i] * cantidad;
            console.log(` debes pagar ${total[i]} $ por  ${cantidad[i]}  de ${Name[i]} \n `);
            console.log(`stock restante ${quantity[i]}:\n `);
        }
    }
    if (!found) {
        console.log("Producto no encontrado.\n");
    }
}

function Stock() {
    do {
        let found = false;
        let Id2 ;
        console.log("Presione 1 para renovar, 2 para quitar o 3 para salir");
        casos = parseInt(prompt("") || "0");

        switch (casos) {
            case 1:
                console.log("ID \tMedicamentos");
                for (let i = 0; i < id.length; i++) {
                    console.log(id[i] + "\t" + Name[i]);
                }
                console.log("Ingrese el ID del producto a modificar stock:");
                Id2 = prompt("") || "";

                for (let i = 0; i < id.length; ++i) {
                    if (id[i] === Id2) {
                        found = true;
                        console.log(`Ingrese la cantidad de ${Name[i]} que deseas renovar (quedan ${quantity[i]} disponibles)`);
                        cantidad = parseFloat(prompt("") || "0");

                        quantity[i] += cantidad;

                        console.log(`Stock renovado: ${quantity[i].toFixed(2)}`);
                    }
                }
                if (!found) {
                    console.log("Producto no encontrado.");
                }
                break;
            case 2:
                console.log("ID \tMedicamentos");
                for (let i = 0; i < id.length; i++) {
                    console.log(id[i] + "\t" + Name[i]);
                }
                console.log("Ingrese el ID del producto a modificar stock:");
                 Id2 = prompt("") || "";

                for (let i = 0; i < id.length; ++i) {
                    if (id[i] === Id2) {
                        found = true;
                        console.log(`Ingrese la cantidad de ${Name[i]} que deseas quitar (quedan ${quantity[i]} disponibles)`);
                        cantidad = parseFloat(prompt("") || "0");

                        quantity[i] -= cantidad;
                        if (quantity[i] < 0) {
                            do {
                                quantity[i] += cantidad;
                                console.log("No existe suficiente stock");
                                console.log(`Ingrese la cantidad de ${Name[i]} que deseas quitar (quedan ${quantity[i]} disponibles)`);
                                cantidad = parseFloat(prompt("") || "0");
                                quantity[i] -= cantidad;
                            } while (quantity[i] < 0);
                        }
                        console.log(`Stock restante: ${quantity[i].toFixed(2)}`);
                    }
                }
                if (!found) {
                    console.log("Producto no encontrado.");
                }
                break;
            case 3:
                console.log("salir.\n");
                break;
            default:
                console.log("opcion invalida.\n");
                break;
        }
    } while (casos != 3);
}
