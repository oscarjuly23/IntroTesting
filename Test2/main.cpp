#include <stdio.h>
#include <cstdlib>
#include <cstring>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


typedef struct {
    char* name;
    int age;
}Person;

Person PERSON_create (char* name, int age) {
    Person p;
    p.name = (char*) malloc(strlen(name)+1);
    strcpy(p.name, name);
    p.age = age;
    return p;
}

char * PERSON_getName (Person p) {
    return p.name;
}

int PERSON_getAge (Person p) {
    return p.age;
}

void PERSON_setName (Person* p, char* name) {
    p->name = (char*) malloc(strlen(name)+1);
    strcpy(p->name, name);
}

void PERSON_setAge(Person* p, int age) {
    p->age=age;
}

void PERSON_destroy (Person* p) {
    free(p->name);
    p->age=-1;
}
Person PERSON_undefined () {
    Person p;
    p.name=NULL;
    p.age=-1;
}

int PERSON_isUndefined (Person p) {
    if ((p.name==NULL) && (p.age==-1)) {
        return 1;
    } else {}
}

int PERSON_compareByName (Person p1, Person p2) {
    if (strcmp(p1.name,p2.name)==0) {
        return 0;
    } else if (strcmp(p1.name,p2.name)<0) {
        return 1;
    } else {
        return -1;
    }
}

int PERSON_compareByAge (Person p1, Person p2) {
    if (p1.age==p2.age) {
        return 0;
    } else if (p1.age > p2.age) {
        return 1;
    } else {
        return -1;
    }
}
//Create
TEST_CASE("PERSON CREATE", "[person]") {
Person p = PERSON_create("oscar",22);
REQUIRE( strcmp(p.name,"oscar")==0 );
REQUIRE( p.age == 22 );
}
//getName
TEST_CASE("PERSON getName", "[person]") {
Person p = PERSON_create("oscar",22);
REQUIRE ( strcmp(PERSON_getName(p),"oscar")==0 );
}
//getAge
TEST_CASE("PERSON getAge", "[person]") {
Person p = PERSON_create("oscar",22);
REQUIRE ( PERSON_getAge(p)==22 );
}
//setName
TEST_CASE("PERSON setName", "[person]") {
Person p = PERSON_create("oscar",22);
PERSON_setName(&p,"carles");
REQUIRE ( strcmp(p.name,"carles")==0 );
}
//setAge
TEST_CASE("PERSON setAge", "[person]") {
Person p = PERSON_create("oscar",22);
PERSON_setAge(&p,25);
REQUIRE ( p.age==25 );
}
//destroy
TEST_CASE("PERSON destroy", "[person]") {
Person p = PERSON_create("carles",25);
PERSON_destroy(&p);
REQUIRE ( p.name==NULL );
REQUIRE ( p.age==-1 );
}
//undefined
TEST_CASE("PERSON undefined", "[person]") {
Person p = PERSON_undefined();
REQUIRE ( p.name==NULL);
REQUIRE ( p.age==-1 );
}
//isUndefined
TEST_CASE("PERSON isUndefined", "[person]") {
Person p = PERSON_undefined();
REQUIRE ( PERSON_isUndefined(p)==1);
}
//compareByName
TEST_CASE("PERSON compareByName", "[person]") {
Person p1 = PERSON_create("oscar",22);
Person p2 = PERSON_create("carles",25);
REQUIRE ( PERSON_compareByName(p1,p2)==-1);
}
//compareByAge
TEST_CASE("PERSON compareByAge", "[person]") {
Person p1 = PERSON_create("oscar",22);
Person p2 = PERSON_create("carles",22);
REQUIRE ( PERSON_compareByAge(p1,p2)==0);
}