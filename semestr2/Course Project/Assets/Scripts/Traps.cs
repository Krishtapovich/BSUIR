using UnityEngine;

public class Traps : MonoBehaviour
{
    public GameObject trap;
    public float distance;
    GameObject shrek;
    Animation anim;

    void Start()
    {
        shrek = GameObject.FindGameObjectWithTag("Player");
        anim = trap.GetComponent<Animation>();
    }

    void Update()
    {
        if (Mathf.Abs(shrek.transform.position.x - trap.transform.position.x) <= distance)
        {
            anim.Play();
        }
        else
        {
            anim.Stop();
        }
    }
}