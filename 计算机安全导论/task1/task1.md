## 1.
CIA三元组
机密性（Confidentiality）：这是指确保敏感信息不被未授权的个人、实体或者过程获取。例如，通过加密技术来保护数据，使得只有拥有正确密钥的人才能够读取信息的内容。

完整性（Integrity）：确保信息在传输过程中不被非法篡改。这可以通过使用数字签名、散列函数等技术来实现，以验证数据是否被修改过。

可用性（Availability）：保证信息和服务能够被授权用户及时访问。这通常涉及到灾难恢复计划、冗余系统和持续的服务监控等措施，以防止服务中断。

AAA框架
认证（Authentication）：确认用户的身份。这通常是通过用户名和密码、双因素认证等方式来完成的。

授权（Authorization）：决定用户可以访问哪些资源或执行哪些操作。这通常涉及到权限管理和访问控制列表（ACLs）。

计费（Accounting）：虽然在某些情况下，AAA中的第三个A也可以表示审计（Audit），但在一般意义上，它指的是记录用户的行为，用于计费或者安全审计的目的。

区别
目标不同：CIA关注的是信息本身的安全性，即信息的机密性、完整性和可用性；而AAA关注的是用户访问控制，确保只有正确的用户才能访问相应的资源。
侧重点不同：CIA侧重于保护信息不被非法访问、篡改或丢失，而AAA侧重于确认用户身份、分配访问权限以及记录用户活动。
实施技术不同：CIA的实现可能包括加密算法、散列函数、防火墙等技术；而AAA则可能包括身份验证协议、访问控制机制、日志记录和审计系统等。
在计算机安全的实践中，CIA和AAA常常需要协同工作，以确保既保护了信息的安全，又合理地管理了用户访问权限，从而构建一个更加稳固的安全体系。

## 2
(1) 主要影响了“完整性”和“真实性”
(2) 影响的是“可用性”
(3) 影响的是“保证”和“真实性”

## 3

### 被动攻击

被动攻击通常是指攻击者试图获取系统的信息，但不会直接影响到系统资源。被动攻击的目的是搜集数据，而不是破坏或者篡改数据。

例子：

  **监听（Eavesdropping）或嗅探（Sniffing）：** 攻击者通过监听网络流量来搜集未加密的信息。例如，攻击者可能会在不安全的网络上嗅探信用卡信息或登录凭证。

### 主动攻击

主动攻击是指攻击者企图直接影响系统的操作，修改数据，或者创建虚假的数据。这类攻击会直接与系统交互，试图绕过或破坏安全措施。

例子：

**中间人攻击（Man-in-the-Middle, MITM）：** 攻击者插入到通信双方之间，拦截并可能修改通信双方的信息。例如，攻击者可能会在用户和银行之间的通信中拦截并修改转账请求。

### 主要区别

- **影响：** 被动攻击通常不会直接影响系统的正常运行，而是悄无声息地搜集信息。相反，主动攻击会直接影响系统的运行和数据的完整性。

- **侦测难度：** 被动攻击更难以侦测，因为它不会改变系统的正常行为或数据。主动攻击由于会影响系统的正常运行，因此相对容易被侦测和防御。

- **攻击目的：** 被动攻击的目的通常是数据收集和监视，而主动攻击的目的则是破坏、篡改或控制系统资源。

- **对抗措施：** 对被动攻击的防御通常包括加强数据加密和保护通信隐私。而对抗主动攻击则需要采取包括防火墙、入侵检测系统和安全协议等在内的更多措施。