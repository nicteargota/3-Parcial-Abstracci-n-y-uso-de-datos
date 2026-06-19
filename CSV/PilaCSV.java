import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;
import java.util.Stack;

class Alumno {

    String nombre;
    int edad;

    Alumno(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }
}

public class PilaCSV {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            Stack<Alumno> pila = new Stack<>();

            for (int i = 1; i <= 3; i++) {

                System.out.println("Alumno " + i);

                System.out.print("Nombre: ");
                String nombre = sc.nextLine();

                System.out.print("Edad: ");
                int edad = sc.nextInt();
                sc.nextLine();

                pila.push(new Alumno(nombre, edad));
            }

            OutputStreamWriter archivo =
                    new OutputStreamWriter(
                            new FileOutputStream("pila.csv"),
                            StandardCharsets.UTF_8);

            archivo.write("Nombre,Edad\n");

            while (!pila.empty()) {

                Alumno a = pila.pop();

                archivo.write(a.nombre + "," + a.edad + "\n");
            }

            archivo.close();

            System.out.println("Archivo CSV creado");

        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}
