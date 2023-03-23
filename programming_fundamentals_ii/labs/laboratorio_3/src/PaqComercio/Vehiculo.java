package PaqComercio;

import java.io.*;

abstract class Vehiculo {
    private String marca;
    private String modelo;
    private String matricula;



    public Vehiculo(String marca, String modelo, String matricula) {
        this.marca = marca;
        this.modelo = modelo;
        this.matricula = matricula;
    }



    public String getMarca() { return this.marca; }
    public void setMarca(String marca) { this.marca = marca; }

    public String getModelo() { return this.modelo; }
    public void setModelo(String modelo) { this.modelo = modelo; }

    public String getMatricula() { return this.matricula; }
    public void setMatricula(String matricula) {this.matricula = matricula; }


    @Override
    public abstract String toString();

    // TODO: implementar con clone (de Object)
    public Object clone() {
        Object copia = null;

        try {
            // Serializar objeto
            ByteArrayOutputStream bos = new ByteArrayOutputStream();
            ObjectOutputStream out = new ObjectOutputStream(bos);
            out.writeObject(this);

            // Deserializar objeto
            ByteArrayInputStream bis = new ByteArrayInputStream(bos.toByteArray());
            ObjectInputStream in = new ObjectInputStream(bis);
            copia = in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }

        return copia;
    }

    @Override
    public boolean equals(Object object) {
        if (object instanceof Vehiculo) {
            return this.matricula.equals(((Vehiculo) object).getMatricula());
        }

        return false;
    }
}
