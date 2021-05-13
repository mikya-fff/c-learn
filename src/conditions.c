#include <stdio.h>

int main(){
    //对被调用的函数max进行声明,如果函数定义在主函数之前，则不需要进行声明。因为编译是从上到下进行的
    int max(int age_1,int age_2);
    int age_1,age_2,age_max;
    //传入的变量的地址
    scanf("%d,%d",&age_1,&age_2);
    //调用函数
    age_max=max(age_1,age_2);
    printf("max age is %d\n",age_max);
    return 0;

}

//形式参数，是值传递
int max(int x,int y){
    int z;
    //if判断
    if(x>y){
        z=x;
    }
    else{
        z=y;
    }
    return z;
}

docker run -d --restart=always \
--name sonarqube -p 9001:9000 \
-e SONAR_JDBC_USERNAME=sonar \
-e SONAR_JDBC_PASSWORD=seuicsoft098 \
-e SONAR_JDBC_URL=jdbc:postgresql://192.168.10.155:5432/sonar \
-e SONAR_SECURITY_REALM=LDAP \
-e LDAP_URL=ldap://192.168.10.155:10389 \
-e LDAP_BINDDN=cn=admin,dc=seuicsoft,dc=com \
-e LDAP_BINDPASSWORD=seuic-soft#807 \
-e LDAP_USER_BASEDN=ou=software,ou=nanjing,dc=seuicsoft,dc=com \
-e LDAP_USER_REQUEST="(&(objectClass=inetOrgPerson)(cn={login}))" \
-e LDAP_USER_REALNAMEATTRIBUTE=cn \
-e LDAP_USER_EMAILATTRIBUTE=mail \
-v /home/test/sonarqube/conf:/opt/sonarqube/conf \
-v /home/test/sonarqube/data:/opt/sonarqube/data \
-v /home/test/sonarqube/logs:/opt/sonarqube/logs \
-v /home/test/sonarqube/extensions:/opt/sonarqube/extensions \
sonarqube:latest