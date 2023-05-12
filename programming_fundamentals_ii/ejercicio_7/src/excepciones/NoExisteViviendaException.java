package excepciones;

public class NoExisteViviendaException extends RuntimeException {
    @Override
    public String getMessage() {
        return "La vivienda indicada no se encuentra en la urbanización.";
    }
}
