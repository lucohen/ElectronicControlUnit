#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class ElectronicControlUnit {
public:
  ElectronicControlUnit();
  ~ElectronicControlUnit();
  void handleCommand(char cCommand);

private:
  bool m_bActivatedHydraulicJacks; // Button A
  bool m_bActivatedBeltTires;       // Button B
  bool m_bActivatedIRIllumination;  // Button E
  void actuateHydraulicJacks();
  void actuateBeltTires();
  void actuateIRIllumination();
};

ElectronicControlUnit::ElectronicControlUnit()
    : m_bActivatedHydraulicJacks(false),
      m_bActivatedBeltTires(false),
      m_bActivatedIRIllumination(false) {
}

ElectronicControlUnit::~ElectronicControlUnit() {
}

void ElectronicControlUnit::handleCommand(char cCommand) {
  switch (cCommand) {
  case 'A':
  case 'a':
    actuateHydraulicJacks();
    break;
  case 'B':
  case 'b':
    actuateBeltTires();
    break;
  case 'E':
  case 'e':
    actuateIRIllumination();
    break;
  default:
    cout << "Invalid command" << endl;
  }
}

void ElectronicControlUnit::actuateHydraulicJacks() {
  if (m_bActivatedHydraulicJacks) {
    m_bActivatedHydraulicJacks = false;
    cout << "Hydraulic jacks deactivated" << endl;
  } else {
    m_bActivatedHydraulicJacks = true;
    cout << "Hydraulic jacks activated" << endl;
    if (m_bActivatedBeltTires) {
      m_bActivatedBeltTires = false;
      cout << "Belt tires deactivated" << endl;
    }
  }
}

void ElectronicControlUnit::actuateBeltTires() {
  if (m_bActivatedBeltTires) {
    m_bActivatedBeltTires = false;
    cout << "Belt tires deactivated" << endl;
  } else {
    m_bActivatedBeltTires = true;
    cout << "Belt tires activated" << endl;
  }
}

void ElectronicControlUnit::actuateIRIllumination() {
  if (m_bActivatedIRIllumination) {
    m_bActivatedIRIllumination = false;
    cout << "Infrared Illumination deactivated" << endl;
  } else {
    m_bActivatedIRIllumination = true;
    cout << "Infrared Illumination activated" << endl;
  }
}

int main() {
  ElectronicControlUnit ecu;
  char cCommand;
  cout << "Press X to turn off Ignition or press a steering wheel button (A, B, or E)" << endl;
  cout << "      (A)" << endl;
  cout << "  (F) (G) (B)" << endl;
  cout << "  (E)     (C)" << endl;
  cout << "      (D)" << endl;
  cin >> cCommand;
  while (cCommand != 'X' && cCommand != 'x') {
    cout << "      (A)" << endl;
    cout << "  (F) (G) (B)" << endl;
    cout << "  (E)     (C)" << endl;
    cout << "      (D)" << endl;
    ecu.handleCommand(cCommand);
    cin >> cCommand;
  }

  return 0;
}