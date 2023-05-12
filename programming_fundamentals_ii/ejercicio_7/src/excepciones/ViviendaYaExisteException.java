package excepciones;

public class ViviendaYaExisteException extends Exception {
    @Override
    public String getMessage() {
        return "Ya existe una vivienda en la posición indicada.";
    }
}
