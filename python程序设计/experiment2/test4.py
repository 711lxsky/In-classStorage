def display_menu():
    print("\n======= 通讯录管理系统 =======")
    print("1. 添加联系人")
    print("2. 删除联系人")
    print("3. 查询联系人信息")
    print("4. 修改联系人信息")
    print("5. 显示所有联系人信息")
    print("6. 退出系统")
    choice = input("请选择操作（输入数字1-6）：")
    return choice

def add_contact(contacts):
    print("\n--- 添加新的联系人 ---")
    name = input("输入联系人姓名：")
    if name in contacts:
        print("错误：该联系人已存在于通讯录中。")
        return
    phone = input("输入电话号码：")
    email = input("输入电子邮件地址：")
    work = input("输入工作单位：")
    contacts[name] = {'电话': phone, '电子邮件': email, '工作单位': work}
    print(f"联系人 {name} 已成功添加到通讯录。")

def delete_contact(contacts):
    print("\n--- 删除联系人 ---")
    name = input("输入要删除的联系人姓名：")
    if name in contacts:
        del contacts[name]
        print(f"联系人 {name} 已从通讯录中删除。")
    else:
        print("错误：找不到该联系人。")

def query_contact(contacts):
    print("\n--- 查询联系人信息 ---")
    name = input("输入要查询的联系人姓名：")
    if name in contacts:
        print(f"姓名：{name}")
        for key, value in contacts[name].items():
            print(f"{key}：{value}")
    else:
        print("错误：找不到该联系人。")

def modify_contact(contacts):
    print("\n--- 修改联系人信息 ---")
    name = input("输入要修改的联系人姓名：")
    if name not in contacts:
        print("错误：找不到该联系人。")
        return
    print("留空并按回车键保留原值。")
    phone = input(f"新的电话号码（当前：{contacts[name]['电话']}）：")
    email = input(f"新的电子邮件地址（当前：{contacts[name]['电子邮件']}）：")
    work = input(f"新的工作单位（当前：{contacts[name]['工作单位']}）：")
    
    if phone:
        contacts[name]['电话'] = phone
    if email:
        contacts[name]['电子邮件'] = email
    if work:
        contacts[name]['工作单位'] = work
    print(f"联系人 {name} 的信息已更新。")

def show_all_contacts(contacts):
    print("\n--- 所有联系人信息 ---")
    if not contacts:
        print("通讯录为空。")
        return
    for name, info in contacts.items():
        print(f"\n姓名：{name}")
        for key, value in info.items():
            print(f"{key}：{value}")

def main():
    contacts = {}
    while True:
        choice = display_menu()
        if choice == '1':
            add_contact(contacts)
        elif choice == '2':
            delete_contact(contacts)
        elif choice == '3':
            query_contact(contacts)
        elif choice == '4':
            modify_contact(contacts)
        elif choice == '5':
            show_all_contacts(contacts)
        elif choice == '6':
            print("您已退出通讯录管理系统。")
            break
        else:
            print("无效输入，请输入数字1至6选择操作。")

if __name__ == "__main__":
    main()
