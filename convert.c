#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

const char* from1to19[] = {"nul", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni", "ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
const char* tens[] = {"", "ti", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"};

char* danishnumbers(int num) {
    // Handle 0 explicitly
    if (num == 0) {
        return strdup("nul");
    }

    // Allocate memory for the result
    char* result = (char*)malloc(200); // Increased memory for larger numbers

    // Handle numbers less than 20
    if (num < 20) {
        return strdup(from1to19[num]);
    }

    // Handle numbers from 20 to 99
    if (num < 100) {
        int tensIndex = num / 10;
        int onesIndex = num % 10;

        if (onesIndex == 0) {
            snprintf(result, 200, "%s", tens[tensIndex]);
        } else {
            snprintf(result, 200, "%s og %s", from1to19[onesIndex], tens[tensIndex]);
        }

        return result;
    }

    // Handle numbers from 100 to 999
    if (num < 1000) {
        int hundredsIndex = num / 100;
        int remainder = num % 100;

        if (remainder == 0) {
            if (hundredsIndex == 1) {
                snprintf(result, 200, "et hundrede");
            } else {
                snprintf(result, 200, "%s hundrede", from1to19[hundredsIndex]);
            }
        } else {
            char* remainderText = danishnumbers(remainder);
            if (hundredsIndex == 1) {
                snprintf(result, 200, "et hundrede %s", remainderText);
            } else {
                snprintf(result, 200, "%s hundrede %s", from1to19[hundredsIndex], remainderText);
            }
            free(remainderText);
        }

        return result;
    }

    // Handle numbers from 1000 to 999999
    if (num < 1000000) {
        int thousandsIndex = num / 1000;
        int remainder = num % 1000;

        if (remainder == 0) {
            if (thousandsIndex == 1) {
                snprintf(result, 200, "et tusinde");
            } else {
                char* thousandsText = danishnumbers(thousandsIndex);
                snprintf(result, 200, "%s tusinde", thousandsText);
                free(thousandsText);
            }
        } else {
            char* remainderText = danishnumbers(remainder);
            if (thousandsIndex == 1) {
                snprintf(result, 200, "et tusinde %s", remainderText);
            } else {
                char* thousandsText = danishnumbers(thousandsIndex);
                snprintf(result, 200, "%s tusinde %s", thousandsText, remainderText);
                free(thousandsText);
            }
            free(remainderText);
        }

        return result;
    }

    snprintf(result, 200, "Number too large to handle");

    return result;
}

