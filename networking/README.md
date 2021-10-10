# Networking
This folder contains come code as well as some theoretical background in the context of networking

## OSI-Model
+ OSI = Open System Interconnections
    + Black Box Model how computers interact with each other over the internet
+ Basically, a message, that should be send over the inter gets from layer 7 to layer one on the client side and then gets from layer 1 to layer 7 in the server side (or the other way around.)

+ OSI has 7 Layers
    - Layer 1: Physical Layer - wire lan, wireless lan
        * The physical layer is used to convert frames into bytes and send them over the hardware for the communication

    - Layer 2: Data Link Layer - Routes, Switches, Ethernets
        - Defines how data is transmitted between two communication partners
        - Defines how long client and server should talk with each other and how much data can be send and what happens if errors occure - i.e. one communication partner closes the connection (e.g. the ethernet cable gets disconnected)
        - Two Sublayers: 
            * LLC - Logical Link Connection
                * Flow control, error-handling, acknolagement 
            * MAC - Media Access Control
                * Responsable for assigning an unique ID for the communication partner. This ID is called MAC-Address - No two devices has the same MAC address 
        - Data packets of the Internet Protocol (IP) are taken and extented by the MAC address of the communication partners 
        + Also, a tail is added to the end of the data packet, in order to make error detection for MAC addresses possable
        ==> After adding the MAC-Address and the error bits, the data packet is ready to send throu the wire. We now not talking about data packets, but about data frames. 

    - Layer 3: Networking Layer - Internet Protocol (IP)
        - Here lives IP, which reads out meta data from the data packets that should be send (i.e. the header of an HTTP message) and recognizes the IP-address and the socket where the packet should be send to. 
            - This means, we use the information that is stored in the data of the transport layer (IP-address and port in the header of the transport layer protocol) and defines with this information the aim of the data packets
        - Data in layer three is called "Packets"
    - Layer 4: Transport Layer - TCP, UDP, FTP
        * The transport layer is defined by the exchange protocol that is beeing used. 
        * Main Protocols
            - TCP: Fixes some issues with the underlying IP-protocol that makes it a relieable way of exchanging data packets
                - It uses Sessions with a TCP handshake and back-checks if data packets were received by the other communication partner
                - Is used, if you want to make sure, that the data that you are sending will get received reliably, error free and complete
                - Works with checksums at the end of every data packet and can trigger the resending of packets that might been damaged or not received if the communication partner recognizes this. Most of the time, you do not need to implement the TCP logic, since the most programming languages has built in TCP sockes (AF_INET sockets)
            - UDP: Is unreliable but, since no checks for the completness of data exchange is been done, it is much faster then TCP.
                - Mostly used in video streaming
    
    - Layer 5: Session Layer - Connection Maintainance
        * Manage connections between client and server
        * Is the equivalent of the Session classes in the boost::asio tutorials of my other ```networking_intro``` repository. 
        * It describes the process of a TCP/IP and TLS handshake and the maintainance of the connection between client and server as long as no one of the both partners end the connection. If one does so, the Session object gets deleted. 
        * Main Tasks: 
            - Opening/Accepting connections
            - Keeping connections alive, as long as client and server want this
            - Closing the connection gracefully if one of the client-server partners ends the connection

    - Layer 6: Presentation Layer - Translates Data in suitable format
        * Three functionallities: 
            - Encryption and Decryption - The request from the Layer 7 gets encrypted (and on server side decrypted)
            - Serialization and Deserialization - datastructures from the application code get serialized to be in a useful format to get transmitted throu the network
            - Compression - compression of the bytes of the serialized data by maintaining the information

    - Layer 7: Application Layer - End-User application protocols (HTTP, DNS, SMTP)
        * Making GET, POST, DELETE, ... requests over http

+ Each layer just communicates with the next layer above and below it
+ Reference model --> You can not use the model in the real world, it just helps you to understand networking

### TCP/IP Model
+ Also a black box model that CAN be used to implement networking applications (instead of the OSI Model)
+ Layers: 
    - Application Layer
    - Transport Layer 
    - Network Layer 
    + Network Interface Layer


+ Reference: https://www.freecodecamp.org/news/osi-model-computer-networking-for-beginners/