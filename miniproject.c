#include <stdio.h>

#define MAX_SEATS 10  // Maximum number of seats

// Function declarations
void displaySeats(char seats[], int totalSeats);
void bookSeat(char seats[], int totalSeats);
void cancelReservation(char seats[], int totalSeats);
void generateTicket(int seatNumber);

int main() {
    char seats[MAX_SEATS] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}; // 'A' represents Available seat
    int choice;

    while (1) {
        printf("\nBus Reservation System\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats, MAX_SEATS);
                break;
            case 2:
                bookSeat(seats, MAX_SEATS);
                break;
            case 3:
                cancelReservation(seats, MAX_SEATS);
                break;
            case 4:
                printf("Thank you for using the Bus Reservation System.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display seat availability
void displaySeats(char seats[], int totalSeats) {
    printf("\nSeat Availability:\n");
    for (int i = 0; i < totalSeats; i++) {
        printf("Seat %d: %c\n", i + 1, seats[i]);
    }
}

// Function to book a seat
void bookSeat(char seats[], int totalSeats) {
    int seatNumber;
    printf("\nEnter seat number to book (1 to %d): ", totalSeats);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > totalSeats) {
        printf("Invalid seat number!\n");
        return;
    }

    if (seats[seatNumber - 1] == 'B') {
        printf("Seat %d is already booked! Choose another seat.\n", seatNumber);
        return;
    }

    seats[seatNumber - 1] = 'B';  // Mark the seat as booked
    printf("Seat %d has been successfully booked.\n", seatNumber);
    generateTicket(seatNumber);
}

// Function to cancel a reservation
void cancelReservation(char seats[], int totalSeats) {
    int seatNumber;
    printf("\nEnter seat number to cancel booking (1 to %d): ", totalSeats);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > totalSeats) {
        printf("Invalid seat number!\n");
        return;
    }

    if (seats[seatNumber - 1] == 'A') {
        printf("Seat %d is not booked! Choose a booked seat to cancel.\n", seatNumber);
        return;
    }

    seats[seatNumber - 1] = 'A';  // Mark the seat as available
    printf("Booking for seat %d has been canceled.\n", seatNumber);
}

// Function to generate a ticket
void generateTicket(int seatNumber) {
    printf("\n-------- TICKET --------\n");
    printf("Seat Number: %d\n", seatNumber);
    printf("Status: Booked\n");
    printf("Thank you for booking with us!\n");
}
