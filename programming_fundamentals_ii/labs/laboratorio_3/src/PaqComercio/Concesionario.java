package PaqComercio;

public class Concesionario extends Comercio {
    private VehiculoVenta[] v;
    private VehiculoParaReparar[] r;



    /*######################################### Constructores ##############################################*/

    /*######################################################################################################*/



    /*####################################### Getters y setters ############################################*/
    /*######################################################################################################*/



    /*######################################### Otros métodos ##############################################*/
    public String toStringStock(int producto) {
        StringBuffer stock = new StringBuffer();

        for (int i = 0; i < v.length && v[i] != null; i++) {
            stock.append(this.v[i].getMarca() + " " + this.v[i].getModelo() + " - Stock:" + super.getStock(i)
                    + "\n");
        }

        return stock.toString();
    }


    /*######################################################################################################*/
}
