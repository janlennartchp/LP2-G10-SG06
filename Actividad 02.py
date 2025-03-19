class Producto:
    def __init__(self, nombre, precio, cantidadEnInventario):
        """Inicializa un producto con nombre, precio y cantidad en inventario"""
        self.nombre = nombre
        self.precio = precio
        self.cantidadEnInventario = cantidadEnInventario

    def getNombre(self):
        return self.nombre  # Devuelve el nombre del producto

    def getPrecio(self):
        return self.precio  # Devuelve el precio del producto

    def getCantidadEnInventario(self):
        return self.cantidadEnInventario  # Devuelve la cantidad en inventario

    def setNombre(self, nombre):
        self.nombre = nombre  # Modifica el nombre del producto

    def setPrecio(self, precio):
        self.precio = precio  # Modifica el precio del producto

    def setCantidadEnInventario(self, cantidad):
        self.cantidadEnInventario = cantidad  # Modifica la cantidad en inventario


class Pedido:
    def __init__(self):
        """Inicializa un pedido con listas vacías para productos y cantidades"""
        self.productos = []
        self.cantidades = []

    def agregarProducto(self, producto, cantidad):
        """Agrega un producto al pedido si hay suficiente stock"""
        if 0 < cantidad <= producto.getCantidadEnInventario():
            self.productos.append(producto)  # Agrega el producto a la lista
            self.cantidades.append(cantidad)  # Agrega la cantidad solicitada
            producto.setCantidadEnInventario(producto.getCantidadEnInventario() - cantidad)  # Reduce el stock
        else:
            print("Cantidad inválida para:", producto.getNombre())  # Mensaje si la cantidad no es válida

    def mostrarPedido(self):
        """Muestra los productos en el pedido con sus cantidades y el total"""
        print("\nResumen del pedido:")
        total = 0
        for i in range(len(self.productos)):
            print(f"{self.productos[i].getNombre()} --> cantidad: {self.cantidades[i]} - precio: {self.productos[i].getPrecio()}")
            total += self.productos[i].getPrecio() * self.cantidades[i]
        print(f"Total del pedido: {total}")


def poner_datos():
    """Crea productos, los agrega a un pedido y muestra los detalles"""
    # Crear productos
    pizarra = Producto("Pizarra", 80, 10)
    mesa = Producto("Mesa", 230, 25)
    silla = Producto("Silla", 55, 60)
    computadora = Producto("Computadora", 2000, 8)

    # Crear pedido y agregar productos
    pedido_agregado = Pedido()
    pedido_agregado.agregarProducto(pizarra, 1)
    pedido_agregado.agregarProducto(mesa, 5)
    pedido_agregado.agregarProducto(silla, 3)
    pedido_agregado.agregarProducto(computadora, 3)

    # Mostrar detalles del pedido
    pedido_agregado.mostrarPedido()


# Ejecutar la función para probar el programa
poner_datos()
