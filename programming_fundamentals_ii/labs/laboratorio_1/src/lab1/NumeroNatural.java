package lab1;

public class NumeroNatural {
    private int numero;

    public void setNumero(int numero) {
        if ( numero >= 0 ) {
            this.numero = numero;
        }
    }

    public int getNumero() { return this.numero; }

    public void incrementar() { this.numero++; }

    public void decrementar() {
        if ( numero > 0 ) {
            this.numero--;
        }
    }

    public boolean esPar() {
        return this.numero % 2 == 0;
    }

    public boolean esPrimo() {
        if (this.numero <= 1) { return false; }

        for ( int i = 2; i <= this.numero/2; i++ ) {
            if ( numero % i == 0 ) { return false; }
        }

        return true;
    }

    public boolean esPerfecto() {
        int suma = 0;

        for ( int i = 1; i <= this.numero/2; i++ ) {
            if ( this.numero % i == 0 ) suma += i;
        }

        return suma == this.numero;
    }

    public int pow ( int exponente ) {
        int potencia = this.numero;

        for ( int i = 1; i < exponente; i++ ) {
            potencia *= this.numero;
        }

        return potencia;
    }

    public double half() {
        return (double)this.numero/2;
    }

    public NumeroNatural distancia( NumeroNatural num ) {
        int res = this.numero - num.numero;

        if ( res < 0 ) { res = -res; }

        NumeroNatural n = new NumeroNatural();
        n.numero = res;

        return n;
    }

    public void syncToMinor( NumeroNatural n ) {
        if ( this.numero < n.getNumero() ) {
            n.setNumero(this.numero);
        } else {
            this.numero = n.getNumero();
        }
    }
}
