# Hospital Management System

## Description

This is a console-based Hospital Management System implemented in C++. It allows for the management of hospital branches, doctors, and patients, including functionalities for adding, displaying, searching, and removing records. The system also supports booking and updating patient appointments.

## Features

- **Branch Management**: Add, display, search, and remove hospital branches.
- **Doctor Management**: Add, display, and remove doctor records, including specialization and associated hospital branch.
- **Patient Management**: Add, display, search, remove, and update patient information.
- **Appointment System**: Book and manage patient appointments.
- **Console-Based Interface**: Interactive menu-driven interface for easy navigation and operation.

## Project Structure

```
hospital-management-system/
├── hospital_managment_system.cpp   # Main source code file containing all logic for the system.
├── hospital_managment_system.exe   # (Windows) Executable file of the compiled program.
└── README.md                       # This README file.
```

## Getting Started

### Prerequisites

To compile and run this project, you will need a C++ compiler. GCC (GNU Compiler Collection) is recommended.

-   **GCC (g++)**: Available on Linux, macOS (via Xcode Command Line Tools), and Windows (via MinGW or Cygwin).

### Installation

1.  **Clone the repository**:
    ```bash
    git clone https://github.com/Ahmed-Al-Mohammadi/hospital-management-system.git
    cd hospital-management-system
    ```

2.  **Compile the source code**:
    Open your terminal or command prompt, navigate to the `hospital-management-system` directory, and compile the C++ file:
    ```bash
    g++ hospital_managment_system.cpp -o hospital_management_system
    ```
    This command will create an executable file named `hospital_management_system` (or `hospital_management_system.exe` on Windows).

### Running the Application

To run the compiled application, execute the following command in your terminal:

```bash
./hospital_management_system
```
(On Windows, you might run `hospital_management_system.exe`)

## Usage

Upon running the application, you will be presented with a main menu:

```
FOR HOSPITAL
1. Add a new branch.
2. Remove branch.
3. Display branches.
4. Search for branch by Id.
***********************************
FOR DOCTOR 
5. Add a new doctor.
6. Remove a doctor.
7. Display All Appointment.
8. Display doctor.
***********************************
FOR PATIENT
9. Add a new patient.
10. Remove a patient
11. Book Appointment.
12. Display patient.
13. Search for patient by Name
14. Update patient information.
0. Exit.
***********************************
Enter your choice:
```

Enter the number corresponding to the action you wish to perform and follow the on-screen prompts.

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, please:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/YourFeature`).
3.  Make your changes.
4.  Commit your changes (`git commit -m 'Add some feature'`).
5.  Push to the branch (`git push origin feature/YourFeature`).
6.  Open a Pull Request.

## License

This project is licensed under the MIT License - see the `LICENSE` file in the repository for details.

## Contact

For any questions or suggestions, please open an issue in the GitHub repository.
