#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to resolve a domain name to an IP address
void getIpAddress(char *domain)
{
    struct hostent *host;
    struct in_addr **addr_list;

    // Get the host information
    if ((host = gethostbyname(domain)) == NULL)
    {
        printf("Could not resolve %s\n", domain);
        return;
    }

    // Extract the list of IP addresses
    addr_list = (struct in_addr **)host->h_addr_list;

    printf("%s: %s\n", domain, inet_ntoa(*addr_list[0]));
}

int main()
{
    char domain[256];

    printf("Enter domain names to resolve them to IP addresses.\n");
    printf("Type 'exit' to quit the program.\n");

    while (1)
    {
        printf("Enter domain name: ");
        scanf("%255s", domain);

        // Exit the loop if the user types "exit"
        if (strcasecmp(domain, "exit") == 0)
        {
            break;
        }

        // Resolve and display the IP address
        getIpAddress(domain);
    }

    return 0;
}


import java.net.InetAddress;
import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Domain name : eg:facebook.com ");
        String Domain_name = sc.nextLine();
        System.out.println(InetAddress.getByName(Domain_name).getHostAddress());
    }
}
