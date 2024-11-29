#include <iostream>
using namespace std;

// Node structure to represent entities in the hospital system
struct node {
    int Id;
    string name;
    string location;  // Only used for branches
    string specialization;  // Used for doctors
    string hospital_branch;  // Used for doctors
    string Appointment;  // Used for patients
    string address;  // Used for patients
    node* next;
};

// Hospital Management System class
class HospitalManagementSystem {
public:
    node* branchList;   // List of hospital branches
    node* doctorList;   // List of doctors
    node* patientList;  // List of patients

public:
    // Constructor to initialize lists
    HospitalManagementSystem() {
        branchList = doctorList = patientList = nullptr;
    }

    // Add a new branch to the system
    void addbranch(int Id, const string& name, const string& location) {
        node* newnode = new node{Id, name, location, "", "", "", "", nullptr};
        if (branchList == nullptr) {
            branchList = newnode;
            newnode->next = nullptr;
        }
        else {
            node* temp = branchList;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Add a new patient to the system
    void addpatient(int Id, const string& name, const string& address, const string& Appointment) {
        node* newnode = new node{Id, name, "", "", "", Appointment, address, nullptr};

        if (patientList == nullptr) {
            patientList = newnode;
            newnode->next = nullptr;
        }
        else {
            node* temp = patientList;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Add a new doctor to the system
    void adddoctor(int Id, const string& name, const string& hospital_branch, const string& specialization) {
        node* newnode = new node{Id, name, hospital_branch, specialization, "", "", "", nullptr};

        if (doctorList == nullptr) {
            doctorList = newnode;
            newnode->next = nullptr;
        }
        else {
            node* temp = doctorList;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Display hospital branches
    void displayBranch() {
        node* temp = branchList;
        while (temp != nullptr) {
            cout << "Id: " << temp->Id << "\n";
            cout << "name: " << temp->name << "\n";
            cout << "location: " << temp->location << "\n";
            temp = temp->next;
        }
    }

    // Display doctors information
    void displaydoctor() {
        node* temp = doctorList;
        while (temp != nullptr) {
            cout << "Id: " << temp->Id << "\n";
            cout << "name: " << temp->name << "\n";
            cout << "specialization: " << temp->specialization << "\n";
            cout << "hospital_branch: " << temp->hospital_branch << "\n";
            temp = temp->next;
        }
    }

    // Display appointments of all Patient
    void displayallAppointment() {
        node* temp = patientList;
        while (temp != nullptr) {
            cout << "Appointment: " << temp->Appointment << "\n";
            temp = temp->next;
        }
    }

    // Display patients information
    void displaypatient() {
        node* temp = patientList;
        while (temp != nullptr) {
            cout << "Id: " << temp->Id << "\n";
            cout << "name: " << temp->name << "\n";
            cout << "address: " << temp->address << "\n";
            cout << "Appointment: " << temp->Appointment << "\n";
            temp = temp->next;
        }
    }

    // Search for a branch by ID
    node* searchBranchById(int Id) {
        node* temp = branchList;
        while (temp != nullptr) {
            if (temp->Id == Id) {
         
                cout<<"the Id of branch is :"<<temp->Id<< "\n";
                cout<<"the name of branch is :"<<temp->name<< "\n";
                   cout<<"the location of branch is :"<<temp->location<< "\n";
                       return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Search for a doctor by ID
    node* searchdoctorById(int Id) {
        node* temp = doctorList;
        while (temp != nullptr) {
            if (temp->Id == Id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Search for a patient by ID
    node* searchpatientById(int Id) {
        node* temp = patientList;
        while (temp != nullptr) {
            if (temp->Id == Id) {
                cout<<temp->Id<< "\n";
              
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Search for a patient by name
    node* searchpatietByname(string name) {
        node* temp = patientList;
        while (temp != nullptr) {
            if (temp->name == name) {
        cout<<"the Id of patient is :"<<temp->Id<< "\n";
                cout<<"the Name of patient is :"<<temp->name<< "\n";
                   cout<<"the Address of patient is :"<<temp->address<< "\n";
                 cout<<"the Appointment of patient is :"<<temp->Appointment<< "\n";
               
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Remove a patient
    void Removepatient(int value) {
        if (patientList == nullptr) cout << "empty";
        else if (searchpatientById(value)) {
            node* temp1 = patientList;
            node* temp2 = nullptr;
            if (patientList->Id == value) {
                patientList = patientList->next;
                delete temp1;
                cout << "node deleted" << "\n";
            }
            else {
                while ((temp1 != nullptr) && (temp1->Id != value)) {
                    temp2 = temp1;
                    temp1 = temp1->next;
                }
                if (temp1 != nullptr) {
                    temp2->next = temp1->next;
                    delete (temp1);
                    cout << "node deleted" << "\n";
                }
                else {
                    cout << "not found" << "\n";
                }
            }
        }
        else cout << "not found";
    }

    // Remove a doctor
    void Removedoctor(int value) {
        if (doctorList == nullptr) cout << "empty";
        else if (searchdoctorById(value)) {
            node* temp1 = doctorList;
            node* temp2 = nullptr;
            if (doctorList->Id == value) {
                doctorList = doctorList->next;
                delete temp1;
                cout << "node deleted" << "\n";
            }
            else {
                while ((temp1 != nullptr) && (temp1->Id != value)) {
                    temp2 = temp1;
                    temp1 = temp1->next;
                }
                if (temp1 != nullptr) {
                    temp2->next = temp1->next;
                    delete (temp1);
                    cout << "node deleted" << "\n";
                }
                else {
                    cout << "not found" << "\n";
                }
            }
        }
        else cout << "not found";
    }

    // Remove a branch
    void Removebranch(int value) {
        if (branchList == nullptr) cout << "empty";
        else if (searchBranchById(value)) {
            node* temp1 = branchList;
            node* temp2 = nullptr;
            if (branchList->Id == value) {
                branchList = branchList->next;
                delete temp1;
                cout << "node deleted" << "\n";
            }
            else {
                while ((temp1 != nullptr) && (temp1->Id != value)) {
                    temp2 = temp1;
                    temp1 = temp1->next;
                }
                if (temp1 != nullptr) {
                    temp2->next = temp1->next;
                    delete (temp1);
                    cout << "node deleted" << "\n";
                }
                else {
                    cout << "not found" << "\n";
                }
            }
        }
        else cout << "not found";
    }

    // Book an appointment for a patient
    void bookAppointment(int patientId, const string& appointmentTime) {
        node* patient = searchpatientById(patientId);

        if (patient != nullptr) {
            patient->Appointment = appointmentTime;
            cout << "Appointment booked for patient " << patient->name << " at " << appointmentTime << "\n";
        } else {
            cout << "Patient not found\n";
        }
    }

    // Update patient information for patient
    void updatePatient(int patientId, const string& name, const string& address, const string& appointmentTime) {
        node* patient = searchpatientById(patientId);

        if (patient != nullptr) {
            patient->Id = patientId;
            patient->name = name;
            patient->address = address;
            patient->Appointment = appointmentTime;
            cout << "Update ID for patient " << patient->Id <<  "\n";
            cout << "Update name for patient " << patient->name <<  "\n";
            cout << "Update address for patient " << patient->address <<  "\n";
            cout << "Update appointmentTime for patient " << patient->Appointment <<  "\n";
        } else {
            cout << "Patient not found\n";
        }
    }
};

int main() {
    HospitalManagementSystem h1;
    int Id , sel;
    string name, location, specialization, hospital_branch, Appointment, address;

    do {
        
        cout <<  "FOR HOSPITAL"<<endl;
        cout <<  "1. Add a new branch." << endl;
        cout << "2. Remove branch." << endl;
        cout << "3. Display branches." << endl;
        cout << "4. Search for branch by Id." << endl;
        cout<<"***********************************"<<endl;
        cout << "FOR DOCTOR "<<endl;
        cout<<"5. Add a new doctor." << endl;
        cout << "6. Remove a doctor." << endl;
        cout << "7. Display All Appointment." << endl;
        cout << "8. Display doctor." << endl;
        cout<<"***********************************"<<endl;
        cout << "FOR PATIENT"<<endl;
        cout <<"9. Add a new patient." << endl;
        cout << "10. Remove a patient" << endl;
        cout << "11. Book Appointment." << endl;
        cout << "12. Display patient." << endl;
        cout << "13. Search for patient by Name" << endl;
        cout << "14. Update patient information." << endl;
        cout << "0. Exit." << endl;
        cout<<"***********************************"<<endl;
        cout << "Enter your choice:";

        cin >> sel;

        switch (sel) {
            case 1:
                // Add a new branch
                cout << "Enter ID for branch: ";
                cin >> Id;
                cout << "Enter name for branch: ";
                cin >> name;
                cout << "Enter location for branch: ";
                cin >> location;
                h1.addbranch(Id, name, location);
                break;

            case 2:
                // Remove branch
                cout << "Enter ID to remove branch: ";
                cin >> Id;
                h1.Removebranch(Id);
                break;

            case 3:
                // Display branches
                cout << "Displaying branches:\n";
                h1.displayBranch();
                break;

            case 4:
                // Search for branch by Id
                cout << "Enter ID to search for branch: ";
                cin >> Id;
                if (h1.searchBranchById(Id)) {
                    cout << "Branch found.\n";
                } else {
                    cout << "Branch not found.\n";
                }
                break;

            case 5:
                // Add a new doctor
                cout << "Enter ID for Doctor: ";
                cin >> Id;
                cout << "Enter name for DOCTOR: ";
                cin >> name;
                cout << "Enter specialization for Doctor: ";
                cin >> specialization;
                cout << "Enter hospital_branch for Doctor: ";
                cin >> hospital_branch;
                h1.adddoctor(Id, name, hospital_branch, specialization);
                break;

            case 6:
                // Remove a doctor
               cout << "Enter ID to remove doctor: ";
                cin >> Id;
                h1.Removedoctor(Id);
                break;

            case 7:
                // Display All Appointments
                cout << "Displaying all Appointments:\n";
                h1.displayallAppointment();
                break;

            case 8:
                // Display doctors
                cout << "Displaying doctors:\n";
                h1.displaydoctor();
                break;

            case 9:
                // Add a new patient
                cout << "Enter ID for Patient: ";
                cin >> Id;
                cout << "Enter name for PATIENT: ";
                cin >> name;
                cout << "Enter address for Patient: ";
                cin >> address;
                cout << "Enter Appointment for Patient: ";
                cin >> Appointment;
                h1.addpatient(Id, name, address, Appointment);
                break;

            case 10:
                // Remove a patient
                cout << "Enter ID to remove patient: ";
                cin >> Id;
                h1.Removepatient(Id);
                break;

            case 11:
                // Book Appointment
                cout << "Enter patient ID to book appointment: ";
                cin >> Id;
                cout << "Enter appointment time: ";
                cin >> Appointment;
                h1.bookAppointment(Id, Appointment);
                break;

            case 12:
                // Display patient
                cout << "Displaying patients:\n";
                h1.displaypatient();
                break;

            case 13:
                // Search for patient by Name
                cout << "Enter name to search for patient: ";
                cin >> name;
                if (h1.searchpatietByname(name)) {
                    cout << "Patient found.\n";
                } else {
                    cout << "Patient not found.\n";
                }
                break;

            case 14:
                // Update patient information
                cout << "Enter patient ID to update information: ";
                cin >> Id;
                cout << "Enter updated name: ";
                cin >> name;
                cout << "Enter updated address: ";
                cin >> address;
                cout << "Enter updated appointment time: ";
                cin >> Appointment;
                h1.updatePatient(Id, name, address, Appointment);
                break;

            case 0:
                // Exit program
                cout << "Exiting program." << endl;
                break;

            default:
                // Invalid choice
                cout << "Invalid choice. Try again." << endl;
                break;
        }
        cout<<"**********************************************************************************\n";
    } while (sel != 0);
return 0;
} 