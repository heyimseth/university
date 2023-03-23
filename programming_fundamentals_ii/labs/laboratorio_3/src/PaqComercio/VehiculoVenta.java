package PaqComercio;

public class VehiculoVenta extends Vehiculo {
    private double precio;
    private int descuento;


    public VehiculoVenta(String marca, String modelo, String matricula,
                         double precio, int descuento) {
        super(marca, modelo, matricula);
        this.precio = precio;
        this.descuento = descuento;
    }


    /**
     * Obtener el precio de venta de este vehículo.
     * @return precio del vehículo.
     */
    public double getPrecio() { return this.precio; }


    /**
     * Asignar un precio de venta a este vehículo.
     * @param precio precio del vehículo.
     */
    public void setPrecio(double precio) { this.precio = precio; }


    /**
     * Obtener el descuento a aplicar en la venta de este vehículo.
     * @return descuento del vehículo.
     */
    public int getDescuento() { return this.descuento; }


    /**
     * Asignar un descuento a aplicar en la venta de este vehículo.
     * @param descuento descuento del vehículo.
     */
    public void setDescuento(int descuento) { this.descuento = descuento; }


    /**
     * Devuelve una cadena indicando la información de venta de este vehículo, incluyendo la marca, modelo,
     * matrícula, precio y descuento a aplicar.
     * @return cadena con la información del vehículo.
     */
    public String toString() {
        return super.getMarca() + " " + super.getModelo() + " tiene un precio de " + this.precio +
                " y se le aplica un " + this.descuento + "% de descuento.";
    }


    /**
     * Realiza una deep copy de este vehículo a la venta.
     * @return la deep copy del vehículo a la venta.
     * @throws CloneNotSupportedException se realiza una llamada al método clone de la clase superior, es
     *      * posible que se lance la excepción si la clase no implementa la interfaz Cloneable.
     */
    public VehiculoVenta clone() throws CloneNotSupportedException {
        VehiculoVenta copia = (VehiculoVenta) super.clone();

        copia.precio = this.precio;
        copia.descuento = this.descuento;

        return copia;
    }
}
