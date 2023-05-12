package excepciones;

public class LugarIncorrectoException extends Exception {
    @Override
    public String getMessage() {
        return "La posición indicada no es válida (fuera de límites o no se corresponde a " +
                "la vivienda indicada).";
    }
}
