using System;
using UnityEngine;
using UnityEngine.InputSystem.DualShock;

public class Check : MonoBehaviour
{
    public GameObject upperButton;
    public GameObject lowerButton;
    public GameObject upperImage;
    public GameObject lowerImage;

    void Update()
    {
        try
        {
            if (DualShock4GamepadHID.current.enabled)
            {
                Cursor.visible = false;
                upperButton.SetActive(false);
                lowerButton.SetActive(false);
                upperImage.SetActive(true);
                lowerImage.SetActive(true);
            }
        }
        catch (NullReferenceException) 
        {
            Cursor.visible = true;
            upperButton.SetActive(true);
            lowerButton.SetActive(true);
            upperImage.SetActive(false);
            lowerImage.SetActive(false);
        }
    }
}
