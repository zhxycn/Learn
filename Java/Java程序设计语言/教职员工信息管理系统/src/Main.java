public class Main {
    public static void main(String[] args) {
        EmployeeInfoManager manager = new EmployeeInfoManager();

        manager.addEmployee(new Faculty("教员", "13000000000", "email@email.com", "助教", "院系", "10000"));
        manager.addEmployee(new Staff("职员", "13100000000", "email@email.com", "初级", "部门", "5000"));

        manager.writeToFile("employees.csv");

        System.out.println(manager.calculateSalaryStatistics());

        manager.readFromFile("employees.csv");
    }
}