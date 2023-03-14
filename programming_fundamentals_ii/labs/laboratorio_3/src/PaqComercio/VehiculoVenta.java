package PaqComercio;

public class VehiculoVenta extends Vehiculo {
    private double precio;
    private int descuento;



    /*########################### Constructores ##############################*/
    public VehiculoVenta(String marca, String modelo, String matricula,
                         double precio, int descuento) {
        super(marca, modelo, matricula);
        this.precio = precio;
        this.descuento = descuento;
    }
    /*########################################################################*/



    /*######################### Getters y Setters ############################*/
    public double getPrecio() { return this.precio; }
    public void setPrecio(double precio) { this.precio = precio; }

    public int getDescuento() { return this.descuento; }
    public void setDescuento(int descuento) { this.descuento = descuento; }
    /*########################################################################*/



    /*########################### Otros métodos ##############################*/
    public String toString() {
        return super.getMarca() + " " + super.getModelo() + " tiene un precio de " + this.precio +
                " y se le aplica un " + this.descuento + "% de descuento.";
    }
    /*########################################################################*/
}
