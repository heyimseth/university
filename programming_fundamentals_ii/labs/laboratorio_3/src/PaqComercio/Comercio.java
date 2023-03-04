package PaqComercio;

public abstract class Comercio {
    private String nombre;
    private String direccion;
    private String cif;
    private double[][] ventasDiarias;
    private int[] stock;
    private Empleado[] empleados;



    /*########################### Constructores ##############################*/

    /*########################################################################*/



    /*######################### Getters y Setters ############################*/
    public String getNombre() { return this.nombre; }
    public void setNombre(String nombre) { this.nombre = nombre; }

    public String getDireccion() { return this.direccion; }
    public void setDireccion(String direccion) { this.direccion = direccion; }

    public String getCif() { return this.cif; }
    public void setCif(String cif) { this.cif = cif; }

    public double getVentasDia(int dia, int mes) {
        if (diaMesValido(dia, mes)) {
            return this.ventasDiarias[mes-1][dia-1];
        }

        return -1;
    }
    public void setVentasDiarias(int dia, int mes, double ventas) {
        if (diaMesValido(dia, mes)) {
            this.ventasDiarias[mes][dia] = ventas;
        }
    }

    public int getStock(int articulo) {
        if (articuloValido(articulo)) {
            return this.stock[articulo];
        }

        return -1;
    }
    public void setStock(int articulo, int cantidad) {
        if (articuloValido(articulo)) {
            this.stock[articulo] = cantidad;
        }
    }
    /*########################################################################*/



    /*########################### Otros métodos ##############################*/
    private boolean diaMesValido(int dia, int mes) {
        return mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31;
    }

    private boolean articuloValido(int articulo) {
        return articulo >= 0 && articulo < this.stock.length;
    }
    /*########################################################################*/
}
