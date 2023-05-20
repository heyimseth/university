package PaqCalc;

import misExcepciones.NoEsUnNumeroExcepcion;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// MANEJO DE EVENTOS EN UNA GUI EN JAVA.
public class Calculadora extends JFrame implements ActionListener, KeyListener {
    private final JTextField t = new JTextField();
    private final JButton[] botones = {
            new JButton("1"), new JButton("2"), new JButton("3"), new JButton("4"),
            new JButton("5"), new JButton("6"), new JButton("7"), new JButton("8"),
            new JButton("9"), new JButton("0"), new JButton("."), new JButton("+"),
            new JButton("-"), new JButton("*"), new JButton("/"), new JButton("=")
    };
    private final JButton bdel = new JButton("Delete");
    private final JButton bclr = new JButton("Clear");
    private final JCheckBox addBotonesChk = new JCheckBox("Otros");
    private final JButton piBtn = new JButton("π");
    private final JButton cosBtn = new JButton("cos");
    private final JButton alicBtn = new JButton("Alic");
    private double a;
    private double b;
    private double resultado;
    private int operador;


    public Calculadora() {
        this.a = this.b = this.resultado = this.operador = 0;


        JFrame f = new JFrame("Calculadora");
        t.setBounds(30, 40, 280, 30);
        f.add(t);

        int indice=0;
        for (int x = 40; x <= 250; x = x + 70) {
            for (int y = 100; y <= 310; y = y + 70) {
                botones[indice].setBounds(x, y, 50, 40);
                f.add(botones[indice]);
                indice++;
            }
        }

        this.addBotonesChk.setBounds(55, 380, 20, 40);
        this.addBotonesChk.setToolTipText("Al habilitarlo, se muestran otras opciones para la calculadora.");
        this.addBotonesChk.setText("Otros");
        this.bdel.setBounds(120, 380, 80, 40);
        this.bclr.setBounds(220, 380, 80, 40);
        this.piBtn.setBounds(330, 100, 50, 40);
        this.cosBtn.setBounds(320, 170, 70, 40);
        this.alicBtn.setBounds(320, 240, 70, 40);

        f.add(addBotonesChk);
        f.add(bdel);
        f.add(bclr);

        f.setLayout(null);
        f.setVisible(true);
        f.setSize(350, 500);
        f.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        f.setResizable(false);
        Image icon = Toolkit.getDefaultToolkit().getImage("icon.png");
        f.setIconImage(icon);
        f.setLocationRelativeTo(null); // se posiciona en el centro de la pantalla

        // AÑADE LOS LISTENERS
        for (JButton boton : this.botones) {
            boton.addActionListener(this);
        }
        this.bclr.addActionListener(this);
        this.bdel.addActionListener(this);
        this.piBtn.addActionListener(this);
        this.cosBtn.addActionListener(this);
        this.alicBtn.addActionListener(this);
        this.t.addKeyListener(this);
        this.addBotonesChk.addActionListener(new GestorBotonesChkBox(f));

        // APARTADO 3. HACER QUE AL PULSAR EL "Aspa" SITUADA EN LA PARTE SUPERIOR DERECHA DE LA VENTANA
        //             EL PROGRAMA NOS PREGUNTE SI ESTAMOS SEGUROS DE SALIR DE LA APLICACIÓN O NO.
        // Al pulsar en "X" (Cerrar), se pregunta al usuario si realmente desea cerrar.
        // Implementado así para evitar implementar la interfaz WindowListener con todos sus métodos
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                Object[] opciones = {"Sí", "No"};
                // Forma anterior
                //if (JOptionPane.showConfirmDialog(f, "¿Deseas cerrar la calculadora?",
                //        "Cerrar", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION) {
                //    System.exit(0);
                //}

                // Forma mejorada, se comprueba que el evento ha sido provocado al intentar cerrar y, si es
                // así, entonces se muestra la ventana para confirmar.
                if (e.getID() == WindowEvent.WINDOW_CLOSING) {
                    if (JOptionPane.showOptionDialog(f, "¿Deseas cerrar la calculadora?",
                            "Cerrar", JOptionPane.YES_NO_OPTION, JOptionPane.YES_NO_OPTION,
                            null, opciones, opciones[1]) == JOptionPane.YES_OPTION) {
                        System.exit(0);
                    }
                }
            }
        });
    }

    // APARTADO 1. HACER QUE EL PROGRAMA RESPONDA ANTE TODOS LOS POSIBLES EVENTOS PROVOCADOS POR
    // EL RATÓN EN EL MANEJO DE LA CALCULADORA
    @Override
    public void actionPerformed(ActionEvent e) {
       /* 1. COMPONER EL NÚMERO PARA QUE APAREZCA EN LA CAJA DE TEXTO

          2. SI SE HA PULSADO EL BOTÓN + CONVERTIR A DOBLE EL TEXTO DE LA CAJA Y PONERLA VACÍA.
             FIJAR EL VALOR DE LA VARIABLE OPERADOR

          3. HACER ALGO SIMILAR CON EL RESTO DE OPERADORES

          4. SI SE PULSA EL BOTÓN  =  LLAMAR AL MÉTODO Operar

          5. SI SE PULSA EL BOTÓN Clear BORRAR LA CAJA DE TEXTO

          6. SI SE PULSA EL BOTÓN Delete USAR UN StringBuilder PARA ELIMINAR UN CARÁCTER DE LA SECUENCIA
        */
        // Comprobamos si la acción a ejecutar es añadir un número o "." y lo añadimos
        for (int i = 0; i < 10; i++) {
            if (e.getSource() == this.botones[i]) {
                this.t.setText(this.t.getText() + this.botones[i].getText());
                return;
            }
        }

        if (e.getSource() == this.bclr) { // Botón de limpiar caja de texto
            this.t.setText("");
        } else if (e.getSource() == this.bdel) { // Botón de eliminar un carácter
            try {
                StringBuilder sb = new StringBuilder(this.t.getText());
                sb.deleteCharAt(this.t.getText().length() - 1);
                this.t.setText(sb.toString());
            } catch (StringIndexOutOfBoundsException e1) {
                this.t.setText("");
            }
        } else if (e.getSource() == this.piBtn) {
            this.t.setText("" + Math.PI);
        } else {
            try {
                if (e.getSource() == this.botones[15]) { // Botón de obtener resultado
                    this.b = this.getOperando();
                    this.Operar();
                } else if (e.getSource() == this.botones[11]) { // Botón de suma
                    this.asignarOperador(0);
                } else if (e.getSource() == this.botones[12]) { // Botón de resta
                    this.asignarOperador(1);
                } else if (e.getSource() == this.botones[13]) { // Botón de producto
                    this.asignarOperador(2);
                } else if (e.getSource() == this.botones[14]) { // Botón de división
                    this.asignarOperador(3);
                } else if (e.getSource() == this.cosBtn) { // Coseno
                    this.asignarOperador(4);
                    this.Operar();
                } else if (e.getSource() == this.alicBtn) { // Alícuota
                    this.asignarOperador(5);
                    this.Operar();
                }
            } catch (NoEsUnNumeroExcepcion e2) {
                this.t.setText(e2.toString());
            } catch (NumberFormatException e3) {
                this.t.setText("El operando no tiene formato numérico.");
            }
        }

        this.t.requestFocus(); // Sitúo el foco de nuevo en la caja de texto.
    }

    private void Operar() throws NoEsUnNumeroExcepcion {
        // REALIZAR LA OPERACIÓN OPORTUNA EN FUNCIÓN DEL VALOR DE LA VARIABLE operador
        // Y MOSTRAR EL VALOR DE LA VARIABLE EN LA CAJA DE TEXTO
            switch (this.operador) {
                case 0: // Suma
                    this.resultado = this.a + this.b;
                    break;
                case 1: // Resta
                    this.resultado = this.a - this.b;
                    break;
                case 2: // Producto
                    this.resultado = this.a * this.b;
                    break;
                case 3: // División
                    if (this.b == 0) {
                        throw new NoEsUnNumeroExcepcion();
                    }
                    this.resultado = this.a / this.b;
                    break;
                case 4: // Coseno
                    this.resultado = cosTaylor(this.a);
                    break;
                case 5: // Alícuota
                    this.t.setText(alicuota((int) this.a));
                    return;
            }
            this.t.setText(String.valueOf(this.resultado));
    }

    private double getOperando() {
        double op = Double.parseDouble(t.getText());
        this.t.setText("");
        return op;
    }

    // APARTADO 2. HACER QUE CUANDO SE PULSE LA TECLA Intro SE REALICE EL CÁLCULO USANDO LA INTERFACE KeyListener
    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_ENTER) {
            this.actionPerformed(new ActionEvent(this.botones[15], KeyEvent.VK_EQUALS, "="));
        } else if (e.getKeyCode() == KeyEvent.VK_F1) {
            this.actionPerformed(new ActionEvent(this.alicBtn, KeyEvent.VK_F1, "Alic"));
        }
    }
    @Override
    public void keyReleased(KeyEvent e) {}
    @Override
    public void keyTyped(KeyEvent e) {}

    // Taylor aproximando con 100 iteraciones
    private double cosTaylor(double rad) {
        double cos = 0;

        for (int i = 0; i < 100; i++) {
            cos += ((Math.pow(-1, i) / this.fact(2*i))*Math.pow(rad, 2*i));
        }

        return cos;
    }

    // Calcular el factorial de un número
    private double fact(int num) {
        if (num == 0) {
            return 1;
        }

        return num * fact(num-1);
    }

    // Para evitar repetición de código al asignar un operador y obtener el primer operando
    private void asignarOperador(int operador) {
            this.a = getOperando();
            this.operador = operador;
    }

    // Alícuota
    private String alicuota(int numero) {
        StringBuilder sb = new StringBuilder(String.valueOf(numero));
        int suma = 0, q = 4;

        if (numero <= 10) {
            return "1";
        }

        while (numero != 1 && q > 0) {
            for (int i = 1; i <= numero / 2; i++) {
                if (numero % i == 0) {
                    suma += i;
                }
            }

            sb.append(", " + suma);
            numero = suma;
            suma = 0;
            q--;
        }

        return sb.toString();
    }

    // Clase privada para gestionar el CheckBox de mostrar botones para PI y Cos
    private class GestorBotonesChkBox implements ActionListener {
        private JFrame jf;

        public GestorBotonesChkBox(JFrame frame) {
            this.jf = frame;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (addBotonesChk.isSelected()) {
                // Mostramos los botones
                t.setBounds(68, 40, 280, 30);
                this.jf.setSize(440, 500);
                this.jf.add(piBtn);
                this.jf.add(cosBtn);
                this.jf.add(alicBtn);
            } else {
                // Ocultamos los botones
                t.setBounds(30, 40, 280, 30);
                this.jf.remove(piBtn);
                this.jf.remove(cosBtn);
                this.jf.remove(alicBtn);
                this.jf.setSize(350, 500);
            }
        }
    }
}
