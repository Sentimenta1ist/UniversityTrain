// Created by sentimental on 4/14/19.

#include "menu.h"

void introduction(void)
{
    printf("\n");
    printf("           SDA            \n");
    printf("           Course Work SDA\n");
    printf("                Written by\n");
    printf("  Ivanenko Olexander KV-82\n");
    printf("                  KPI 2019\n");
    printf("\n\n\n Press Enter to continue...");
    myGetch();
}

void back_menu()
{
    printf("\n\tEnter 0 to back to menu...\n");
    int i = -1;
    scanf("%d",&i);
    if( i == 0)
    {
        clear();
        menu();
    }

}

void vector_sort()
{

        printf("Select option:\n");
        printf(" 1.  Selection_sort\n");
        printf(" 2.  Selection_sort_4\n");
        printf(" 3.  Quick_sort\n");
        int button = -1;
        scanf("%d", &button);
        switch (button)
        {
            case 0:
                clear();
                back_menu();
                break;
            case 1:
                clear();
                memory_vector();
                printf("Measurement of Vector[%d] * P\n\n",N);
                fill_vector(0);
                fill_res_select_vector();
                printf("Ordered. Select. Clock_t = %.3f\n", MeasurementProcessing()*P);
                fill_vector(1);
                fill_res_select_vector();
                printf("Random. Select. Clock_t = %.3f\n", MeasurementProcessing()*P);
                fill_vector(2);
                fill_res_select_vector();
                printf("BackOrdered. Select.Clock_t = %.3f\n", MeasurementProcessing()*P);
                free_vector();
                back_menu();
                break;
            case 2:
                clear();
                memory_vector();
                printf("Measurement of Vector[%d] * P\n\n",N);
                fill_vector(0);
                fill_res_select4_vector();
                printf("Ordered. Select4. Clock_t = %.3f\n", MeasurementProcessing()*P);
                fill_vector(1);
                fill_res_select4_vector();
                printf("Random. Select4. Clock_t = %.3f\n", MeasurementProcessing()*P);
                fill_vector(2);
                fill_res_select4_vector();
                printf("BackOrdered. Select4.Clock_t = %.3f\n", MeasurementProcessing()*P);
                free_vector();
                back_menu();
                break;
            case 3:
                clear();
                memory_vector();
                printf("Measurement of Vector[%d] * P\n\n",N);
                sort_quick_vector(0);
                printf("Ordered. Quick. Clock_t = %.3f\n", MeasurementProcessing()*P);
                sort_quick_vector(1);
                printf("Random. Quick. Clock_t = %.3f\n", MeasurementProcessing()*P);
                sort_quick_vector(2);
                printf("BackOrdered. Quick.Clock_t = %.3f\n", MeasurementProcessing()*P);
                free_vector();
                back_menu();
                break;
            default:
                break;
        }

}

void arr_sort()
{
    printf("Select option:\n");
    printf(" 1.  Selection_sort\n");
    printf(" 2.  Selection_sort_4\n");
    printf(" 3.  Quick_sort\n");
    int button = -1;
    scanf("%i", &button);
    switch (button)
    {
        case 1:
            clear();
            memory_arr();
            printf("Measurement of Arr[%d][%d][%d]\n\n",P,M,N);
            fill_arr(0);
            fill_res_select();
            printf("Ordered. Select. Clock_t = %.3f\n", MeasurementProcessing());
            fill_arr(1);
            fill_res_select();
            printf("Random. Select. Clock_t = %.3f\n", MeasurementProcessing());
            fill_arr(2);
            fill_res_select();
            printf("BackOrdered. Select.Clock_t = %.3f\n", MeasurementProcessing());
            free_arr();
            back_menu();
            break;
        case 2:
            clear();
            memory_arr();
            printf("Measurement of Arr[%d][%d][%d]\n\n",P,M,N);
            fill_arr(0);
            fill_res_select4();
            printf("Ordered. Select_4. Clock_t = %.3f\n", MeasurementProcessing());
            fill_arr(1);
            fill_res_select4();
            printf("Random. Select_4. Clock_t = %.3f\n", MeasurementProcessing());
            fill_arr(2);
            fill_res_select4();
            printf("BackOrdered. Select_4.Clock_t = %.3f\n", MeasurementProcessing());
            free_arr();
            back_menu();
            break;
        case 3:
            clear();
            memory_arr();
            printf("Measurement of Arr[%d][%d][%d]\n\n",P,M,N);
            fill_arr(0);
            sort_quick_arr();
            printf("Ordered. Quick. Clock_t = %.3f\n", MeasurementProcessing());
            fill_arr(1);
            sort_quick_arr();
            printf("Random. Quick. Clock_t = %.3f\n", MeasurementProcessing());
            fill_arr(2);
            sort_quick_arr();
            printf("BackOrdered. Quick.Clock_t = %.3f\n", MeasurementProcessing());
            free_arr();
            back_menu();
            break;
        default:
            break;
    }
}



void table ()
{
    clear();
    printf("\n                      Measurement Arr[%i][%i][%i]\n", P, M, N);
    printf("                        ------------------------------------------------------------------------\n");
    printf("                       |\tordered        |\trandomed       |\tbackOrdered    |\n");
    printf("                       |-----------------------------------------------------------------------|\n");

    float select1,select2,select3;
    memory_arr();
    fill_arr(0);
    fill_res_select();
    select1 = MeasurementProcessing();
    fill_arr(1);
    fill_res_select();
    select2 = MeasurementProcessing();
    fill_arr(2);
    fill_res_select();
    select3 = MeasurementProcessing();
    free_arr();


    printf("     Selection_sort    |\t%-15.3f|\t%-15.3f|\t%-15.3f|\n",select1,select2,select3);
    printf("                       |-----------------------------------------------------------------------|\n");

    float select_41,select_42,select_43;
    memory_arr();
    fill_arr(0);
    fill_res_select4();
    select_41 = MeasurementProcessing();
    fill_arr(1);
    fill_res_select4();
    select_42 = MeasurementProcessing();
    fill_arr(2);
    fill_res_select4();
    select_43 = MeasurementProcessing();
    free_arr();


    printf("     Selection_sort_4  |\t%-15.3f|\t%-15.3f|\t%-15.3f|\n",select_41,select_42,select_43);
    printf("                       |-----------------------------------------------------------------------|\n");


    float quick1,quick2,quick3;
    memory_arr();
    fill_arr(0);
    sort_quick_arr();
    quick1 = MeasurementProcessing();
    fill_arr(1);
    sort_quick_arr();
    quick2 = MeasurementProcessing();
    fill_arr(2);
    sort_quick_arr();
    quick3 = MeasurementProcessing();
    free_arr();


    printf("     Quick_sort        |\t%-15.3f|\t%-15.3f|\t%-15.3f|\n",quick1,quick2,quick3);
    printf("                        ------------------------------------------------------------------------\n");

    // TABLE_OF_VECTOR

    printf("\n                      Measurement Vector[%i] * P\n\n",N);
    printf("                        ------------------------------------------------------------------------\n");
    printf("                       |\tordered        |\trandomed       |\tbackOrdered    |\n");
    printf("                       |-----------------------------------------------------------------------|\n");

    memory_vector();
    fill_vector(0);
    fill_res_select_vector();
    select1 = MeasurementProcessing() * P;
    fill_vector(1);
    fill_res_select_vector();
    select2 = MeasurementProcessing() * P;
    fill_vector(2);
    fill_res_select_vector();
    select3 = MeasurementProcessing() * P;
    free_vector();

    printf("     Selection_sort    |\t%-15.3f|\t%-15.3f|\t%-15.3f|\n",select1,select2,select3);
    printf("                       |-----------------------------------------------------------------------|\n");

    memory_vector();
    fill_vector(0);
    fill_res_select4_vector();
    select_41 = MeasurementProcessing() * P;
    fill_vector(1);
    fill_res_select4_vector();
    select_42 = MeasurementProcessing() * P;
    fill_vector(2);
    fill_res_select4_vector();
    select_43 = MeasurementProcessing() * P;
    free_vector();

    printf("     Selection_sort_4  |\t%-15.3f|\t%-15.3f|\t%-15.3f|\n",select_41,select_42,select_43);
    printf("                       |-----------------------------------------------------------------------|\n");

    memory_vector();
    sort_quick_vector(0);
    quick1 = MeasurementProcessing() * P;
    sort_quick_vector(1);
    quick2 = MeasurementProcessing() * P;
    sort_quick_vector(2);
    quick3 = MeasurementProcessing() * P;
    free_vector();

    printf("     Quick_sort        |\t%-15.3f|\t%-15.3f|\t%-15.3f|\n",quick1,quick2,quick3);
    printf("                        ------------------------------------------------------------------------\n");

}




void menu()
{

    clear();
    printf("Select option:\n");
    printf(" 1.  Vector sorting\n");
    printf(" 2.  3D array sorting\n");
    printf(" 3.  Table of sorting\n");
    printf(" 0.  Exit\n");
    int m = -1;
    while (1)
    {
        scanf("%d",&m);
        switch (m)
        {
            case 0:
            {
                clear();
                return;
            }
            case 1:
            {
                clear();
                vector_sort();
                back_menu();
                break;
            }
            case 2:
            {
                clear();
                arr_sort();
                back_menu();
                break;
            }
            case 3:
            {
                clear();
                table();
                back_menu();
                break;
            }
            default:
                break;
        }
        return;
    }

}

