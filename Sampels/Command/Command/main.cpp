#include <iostream>
#include <functional>

using namespace std;

class CButton
{
public:
	typedef std::function<void(CButton & button)> Action;

	void SetClickAction(const Action& action)
	{
		m_action = action;
	}

	void Click()
	{
		if (m_action)
		{
			m_action(*this);
		}
	}
private:
	Action m_action;
};

void PlayWithButton(CButton & b)
{
	b.Click();
	b.Click();
}

int main()
{
	CButton addCircleBtn;
	CButton addRectangleBtn;

	addCircleBtn.SetClickAction([](CButton & b) {
		cout << "add circle" << endl;
	});
	addRectangleBtn.SetClickAction([](CButton & b) {
		cout << "add rectangle" << endl;
	});

	PlayWithButton(addCircleBtn);
	PlayWithButton(addRectangleBtn);

}