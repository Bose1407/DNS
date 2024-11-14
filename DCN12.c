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