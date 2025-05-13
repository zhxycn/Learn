import java.util.*;
import java.io.*;

public class EmployeeInfoManager {
    private final List<Employee> employees = new ArrayList<>();

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public void writeToFile(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Employee employee : employees) {
                writer.write(employee.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }

    public void readFromFile(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts[0].equals("Faculty")) {
                    Faculty faculty = new Faculty(parts[1], parts[5], parts[6], parts[2], parts[3], parts[4]);
                    addEmployee(faculty);
                } else if (parts[0].equals("Staff")) {
                    Staff staff = new Staff(parts[1], parts[5], parts[6], parts[2], parts[3], parts[4]);
                    addEmployee(staff);
                }
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }

    public String calculateSalaryStatistics() {
        double totalSalary = 0;
        int count = 0;
        for (Employee employee : employees) {
            if (employee instanceof Faculty) {
                totalSalary += Double.parseDouble(((Faculty) employee).getSalary());
                count++;
            } else if (employee instanceof Staff) {
                totalSalary += Double.parseDouble(((Staff) employee).getSalary());
                count++;
            }
        }
        double averageSalary = count == 0 ? 0 : totalSalary / count;
        return "总薪水: " + totalSalary + ", 平均薪水: " + averageSalary;
    }
}
