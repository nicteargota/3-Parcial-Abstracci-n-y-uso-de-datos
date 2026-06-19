import java.io.FileWriter;

class Alumno {

    String nombre;
    int edad;

    Alumno(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }
}

public class TiposTXT {

    public static void main(String[] args) {

        try {

            FileWriter archivo = new FileWriter("tipos.txt");

            // Tipo básico variable
            int edad = 20;

            // Tipo básico arreglo
            int[] numeros = {10, 20, 30};

            // Nuevo tipo variable
            Alumno alumno1 = new Alumno("Ana", 20);

            // Nuevo tipo arreglo
            Alumno[] alumnos = {
                new Alumno("Luis", 21),
                new Alumno("Pedro", 22)
            };

            archivo.write("VARIABLE BASICA\n");
            archivo.write(edad + "\n\n");

            archivo.write("ARREGLO BASICO\n");

            for (int n : numeros) {
                archivo.write(n + "\n");
            }

            archivo.write("\nNUEVO TIPO VARIABLE\n");
            archivo.write(alumno1.nombre + " " + alumno1.edad + "\n");

            archivo.write("\nNUEVO TIPO ARREGLO\n");

            for (Alumno a : alumnos) {
                archivo.write(a.nombre + " " + a.edad + "\n");
            }

            archivo.close();

            System.out.println("TXT creado");

        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}
