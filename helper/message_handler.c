#include "message_handler.h"

/**
* LOGIN HANDLE FUNCTION
**/
void login_msg_request_encoder(char* encode_msg, char* email, char* password){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < MSG_FLAG_LEN) {
        encode_msg[i++] = LOGIN_FLAG[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(email)){
        encode_msg[i++] = email[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(password)){
        encode_msg[i++] = password[t++];
    }
    encode_msg[i++] = '\0';

    return;
}

void login_msg_request_decoder(char* encoded_msg, char* email, char *password){
    int i = MSG_FLAG_LEN + 1, t = 0;
    while(encoded_msg[i] != '\n'){
        email[t++] = encoded_msg[i++];
    }
    email[t] = '\0';
    i++;
    t = 0;
    while(encoded_msg[i] != '\0'){
        password[t++] = encoded_msg[i++];
    }
    password[t] = '\0';
    return;  
}

void login_msg_response_encoder(char* encode_msg, char* username){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < RESPONSE_STATUS_LEN) {
        encode_msg[i++] = RESPONSE_OK[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(username)){
        encode_msg[i++] = username[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void login_msg_response_decoder(char* encoded_msg, char *response_status, char* username){
    int i = 0, t = 0;
    while(i < RESPONSE_STATUS_LEN){
        response_status[t++] = encoded_msg[i++];
    }
    response_status[t] = '\0';
    i++;
    t = 0;
    while(encoded_msg[i] != '\0'){
        username[t++] = encoded_msg[i++];
    }
    username[t] = '\0';
    return;  
}

/**
* SIGNUP HANDLE FUNCTION
**/
void signup_msg_request_encoder(char* encode_msg, char* username, char* email, char* password){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < MSG_FLAG_LEN) {
        encode_msg[i++] = SIGNUP_FLAG[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(username)){
        encode_msg[i++] = username[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(email)){
        encode_msg[i++] = email[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(password)){
        encode_msg[i++] = password[t++];
    }
    encode_msg[i++] = '\0';

    return;
}

void signup_msg_request_decoder(char* encoded_msg, char* username, char* email, char *password){
    int i = MSG_FLAG_LEN + 1, t = 0;

    while(encoded_msg[i] != '\n'){
        username[t++] = encoded_msg[i++];
    }
    username[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\n'){
        email[t++] = encoded_msg[i++];
    }
    email[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\0'){
        password[t++] = encoded_msg[i++];
    }
    password[t] = '\0';
    return;  
}

void signup_msg_response_encoder(char* encode_msg, char* username){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < RESPONSE_STATUS_LEN) {
        encode_msg[i++] = RESPONSE_OK[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(username)){
        encode_msg[i++] = username[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void signup_msg_response_decoder(char* encoded_msg, char *response_status, char* username){
    int i = 0, t = 0;
    while(i < RESPONSE_STATUS_LEN){
        response_status[t++] = encoded_msg[i++];
    }
    response_status[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\0'){
        username[t++] = encoded_msg[i++];
    }
    username[t] = '\0';
    return;  
}

/**
* CREATE REPOSITORY HANDLE FUNCTION
**/
void create_repo_msg_request_encoder(char* encode_msg, char* repo_name){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < MSG_FLAG_LEN) {
        encode_msg[i++] = CREATE_REPO_FLAG[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(repo_name)){
        encode_msg[i++] = repo_name[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void create_repo_msg_request_decoder(char* encoded_msg, char* repo_name){
    int i = MSG_FLAG_LEN + 1, t = 0;

    while(encoded_msg[i] != '\0'){
        repo_name[t++] = encoded_msg[i++];
    }
    repo_name[t] = '\0';
    return;  
}

void create_repo_msg_response_encoder(char* encode_msg, char* repo_name){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < RESPONSE_STATUS_LEN) {
        encode_msg[i++] = RESPONSE_OK[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(repo_name)){
        encode_msg[i++] = repo_name[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void create_repo_msg_response_decoder(char* encoded_msg, char *response_status, char *repo_name){
    int i = 0, t = 0;
    while(i < RESPONSE_STATUS_LEN){
        response_status[t++] = encoded_msg[i++];
    }
    response_status[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\0'){
        repo_name[t++] = encoded_msg[i++];
    }
    repo_name[t] = '\0';
    return;  
}

/**
* LIST REPOSITORIES HANDLE FUNCTION
**/
void list_repo_msg_request_encoder(char* encode_msg){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < MSG_FLAG_LEN) {
        encode_msg[i++] = LIST_REPO_FLAG[t++];
    }
    return;
}

void list_repo_msg_request_decoder(char* encoded_msg){
    // TODO
    return;  
}

void list_repo_msg_response_encoder(char* encode_msg, char* list_repo){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < RESPONSE_STATUS_LEN) {
        encode_msg[i++] = RESPONSE_OK[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(list_repo)){
        encode_msg[i++] = list_repo[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void list_repo_msg_response_decoder(char* encoded_msg, char *response_status, char *list_repo){
    int i = 0, t = 0;
    while(i < RESPONSE_STATUS_LEN){
        response_status[t++] = encoded_msg[i++];
    }
    response_status[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\0'){
        list_repo[t++] = encoded_msg[i++];
    }
    list_repo[t] = '\0';
    return;  
}

/**
* LOGOUT HANDLE FUNCTION
**/
void logout_msg_request_encoder(char* encode_msg){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < MSG_FLAG_LEN) {
        encode_msg[i++] = LOGOUT_FLAG[t++];
    }
    return;
}

void logout_msg_request_decoder(char* encoded_msg){
    // TODO
    return;  
}

void logout_msg_response_encoder(char* encode_msg){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < RESPONSE_STATUS_LEN) {
        encode_msg[i++] = RESPONSE_OK[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void logout_msg_response_decoder(char* encoded_msg, char *response_status){
    int i = 0, t = 0;
    while(i < RESPONSE_STATUS_LEN){
        response_status[t++] = encoded_msg[i++];
    }
    response_status[t] = '\0';
    i++;
    return;  
}

/**
* CLONE A REPOSITORY HANDLE FUNCTION
**/
void clone_repo_msg_request_encoder(char* encode_msg, char* repo_name){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < MSG_FLAG_LEN) {
        encode_msg[i++] = CLONE_REPO_FLAG[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(repo_name)){
        encode_msg[i++] = repo_name[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void clone_repo_msg_request_decoder(char* encoded_msg, char* repo_name){
    int i = MSG_FLAG_LEN + 1, t = 0;

    while(encoded_msg[i] != '\0'){
        repo_name[t++] = encoded_msg[i++];
    }
    repo_name[t] = '\0';
    return;  
}

void clone_repo_msg_response_encoder(char* encode_msg, char* repo_name, char* file_location, char *file_name, char *content){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(i < RESPONSE_STATUS_LEN) {
        encode_msg[i++] = RESPONSE_OK[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(repo_name)){
        encode_msg[i++] = repo_name[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(file_location)){
        encode_msg[i++] = file_location[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(file_name)){
        encode_msg[i++] = file_name[t++];
    }
    encode_msg[i++] = '\n';
    t = 0;

    while(t < strlen(content)){
        encode_msg[i++] = content[t++];
    }
    encode_msg[i++] = '\0';

    return;
}

void clone_repo_msg_response_decoder(char* encoded_msg, char *response_status, char* repo_name, char* file_location, char *file_name, char *content){
    int i = 0, t = 0;
    while(i < RESPONSE_STATUS_LEN){
        response_status[t++] = encoded_msg[i++];
    }
    response_status[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\n'){
        repo_name[t++] = encoded_msg[i++];
    }
    repo_name[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\n'){
        file_location[t++] = encoded_msg[i++];
    }
    file_location[t] = '\0';
    i++;
    t = 0;

    while(encoded_msg[i] != '\n'){
        file_name[t++] = encoded_msg[i++];
    }
    file_name[t] = '\0';
    i++;
    t = 0;
    
    while(encoded_msg[i] != '\0'){
        content[t++] = encoded_msg[i++];
    }
    content[t] = '\0';
    i++;
    t = 0;
        
    return;  
}

/**
* SEND STATUS
**/
void send_status_encoder(char* encode_msg, char* status){
    int i = 0, t = 0;
    bzero(encode_msg, MSG_MAX_LEN);

    while(t < strlen(status)) {
        encode_msg[i++] = status[t++];
    }
    encode_msg[i++] = '\0';
    return;
}

void send_status_decoder(char* encoded_msg, char *status){
    int i = 0, t = 0;
    while(encoded_msg[i] != '\0'){
        status[t++] = encoded_msg[i++];
    }
    status[t] = '\0';
    return;  
}