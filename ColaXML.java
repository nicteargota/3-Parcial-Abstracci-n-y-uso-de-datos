import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Persona {

    String nombre;
    int edad;

    Persona(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }
}

public class ColaXML {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            Queue<Persona> cola = new LinkedList<>();

            for (int i = 1; i <= 3; i++) {

                System.out.println("Persona " + i);

                System.out.print("Nombre: ");
                String nombre = sc.nextLine();

                System.out.print("Edad: ");
                int edad = sc.nextInt();
                sc.nextLine();

                cola.add(new Persona(nombre, edad));
            }

            OutputStreamWriter archivo =
                    new OutputStreamWriter(
                            new FileOutputStream("cola.xml"),
                            StandardCharsets.UTF_8);

            archivo.write("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");

            archivo.write("<personas>\n");

            while (!cola.isEmpty()) {

                Persona p = cola.poll();

                archivo.write("    <persona>\n");
                archivo.write("        <nombre>" + p.nombre + "</nombre>\n");
                archivo.write("        <edad>" + p.edad + "</edad>\n");
                archivo.write("    </persona>\n");
            }

            archivo.write("</personas>");

            archivo.close();

            System.out.println("Archivo XML creado");

        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}
