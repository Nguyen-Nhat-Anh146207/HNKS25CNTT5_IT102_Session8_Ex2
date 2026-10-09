
#include <stdio.h>
struct UserAccount {
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
};
int main() {
    struct UserAccount user_list[100];
    int N;
    int i;
    int total_revenue = 0;
    int downgrade_count = 0;
    int service_fee;
    int penalty_fee;
    int max_devices;

    do {
        printf("Nhap so luong tai khoan (1-100): ");
        scanf("%d", &N);

        if (N < 1 || N > 100) {
            printf("So luong khong hop le! Nhap lai.\n");
        }
    } while (N < 1 || N > 100);

    for (i = 0; i < N; i++) {
        printf("\n--- Tai khoan thu %d ---\n", i + 1);

        printf("Nhap ma tai khoan: ");
        scanf("%d", &user_list[i].user_id);

        printf("Nhap ten tai khoan (khong co khoang trang): ");
        scanf("%49s", user_list[i].username);

        do {
            printf("Nhap ma goi (1-Free, 2-Personal, 3-Family): ");
            scanf("%d", &user_list[i].plan_type);

            if (user_list[i].plan_type < 1 || user_list[i].plan_type > 3) {
                printf("Ma goi khong hop le! Nhap lai.\n");
            }
        } while (user_list[i].plan_type < 1 || user_list[i].plan_type > 3);

        do {
            printf("Nhap so ngay no cuoc: ");
            scanf("%d", &user_list[i].days_overdue);

            if (user_list[i].days_overdue < 0) {
                printf("So ngay no khong duoc am! Nhap lai.\n");
            }
        } while (user_list[i].days_overdue < 0);

        do {
            printf("Nhap so thiet bi dang ket noi: ");
            scanf("%d", &user_list[i].active_devices);

            if (user_list[i].active_devices < 0) {
                printf("So thiet bi khong duoc am! Nhap lai.\n");
            }
        } while (user_list[i].active_devices < 0);
    }

    for (i = 0; i < N; i++) {
        if (user_list[i].days_overdue >= 3) {
            if (user_list[i].plan_type != 1) {
                user_list[i].plan_type = 1;
                downgrade_count++;
            }
        }

        if (user_list[i].plan_type == 1) {
            service_fee = 0;
            max_devices = 1;
        } else if (user_list[i].plan_type == 2) {
            service_fee = 120000;
            max_devices = 1;
        } else {
            service_fee = 250000;
            max_devices = 5;
        }

        penalty_fee = 0;

        if (user_list[i].plan_type == 2 &&
            user_list[i].active_devices > max_devices) {
            penalty_fee = (user_list[i].active_devices - max_devices) * 30000;
        }
        service_fee += penalty_fee;
        total_revenue += service_fee;
    }

    printf("\n================ BAO CAO DOI SOAT ================\n");
    printf("%-10s %-20s %-8s %-12s %-10s %-20s\n",
           "Ma TK", "Ten TK", "Ma Goi",
           "So Thiet Bi", "So Ngay No", "Phi Thuc Thu");

    printf("--------------------------------------------------------------------------\n");
    for (i = 0; i < N; i++) {
        if (user_list[i].plan_type == 1) {
            service_fee = 0;
            max_devices = 1;
        } else if (user_list[i].plan_type == 2) {
            service_fee = 120000;
            max_devices = 1;
        } else {
            service_fee = 250000;
            max_devices = 5;
        }

        penalty_fee = 0;

        if (user_list[i].plan_type == 2 && user_list[i].active_devices > max_devices) {
            penalty_fee = (user_list[i].active_devices - max_devices) * 30000;
        }

        service_fee += penalty_fee;

        printf("%-10d %-20s %-8d %-12d %-10d %-20d\n", user_list[i].user_id, user_list[i].username, user_list[i].plan_type, user_list[i].active_devices, user_list[i].days_overdue, service_fee);
    }
    printf("--------------------------------------------------------------------------\n");
    printf("Tong doanh thu thuc te: %d VND\n", total_revenue);
    printf("So tai khoan bi ha cap: %d\n", downgrade_count);
    return 0;
}