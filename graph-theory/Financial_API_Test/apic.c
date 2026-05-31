#include <stdio.h>
#include <curl/curl.h>
#include <jansson.h>
#include <time.h>
#include <string.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, char *userp) {
    strncat(userp, (char *)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl = curl_easy_init();
    char response[4096] = {0};
    
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.coinpaprika.com/v1/tickers/btc-bitcoin");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)response);
    
    CURLcode res = curl_easy_perform(curl);
    
    if (res == CURLE_OK) {
        json_error_t error;
        json_t *root = json_loads(response, 0, &error);
        
        double price = json_real_value(json_object_get(
            json_object_get(root, "quotes"), "USD"));
        const char *id = json_string_value(json_object_get(root, "id"));
        const char *name = json_string_value(json_object_get(root, "name"));
        
        printf("Bitcoin Price: $%.2f\n", price);
        printf("ID: %s\n", id);
        printf("Name: %s\n", name);
        
        json_decref(root);
    }
    
    curl_easy_cleanup(curl);
    return 0;
}