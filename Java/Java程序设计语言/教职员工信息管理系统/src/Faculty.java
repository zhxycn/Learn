public class Faculty extends Employee {
    private String level;
    private String department;
    private String salary;

    public Faculty(String name, String phone, String email, String level, String department, String salary) {
        super(name, phone, email);
        setLevel(level);
        setDepartment(department);
        setSalary(salary);
    }

    public String getLevel() {
        return level;
    }

    public void setLevel(String level) {
        this.level = level;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public String getSalary() {
        return salary;
    }

    public void setSalary(String salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Faculty," + getName() + "," + getLevel() + "," + getDepartment() + "," + getSalary() + "," + getPhone() + "," + getEmail();
    }
}