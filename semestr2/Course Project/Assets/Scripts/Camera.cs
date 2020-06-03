using UnityEngine;

public class Camera : MonoBehaviour
{

    public float damping = 1.5f;
    public Vector2 offset = new Vector2(2f, 1f);
    public bool faceRight;
    public GameObject pauseMenu;
    public GameObject deathMenu;
    public GameObject finishMenu;
    Transform shrek;
    int lastX;

    void Start()
    {
        offset = new Vector2(Mathf.Abs(offset.x), offset.y);
        FindShrek(faceRight);
    }

    public void FindShrek(bool playerFaceRight)
    {
        shrek = GameObject.FindGameObjectWithTag("Player").transform;
        lastX = Mathf.RoundToInt(shrek.position.x);
        if (playerFaceRight)
        {
            transform.position = new Vector3(shrek.position.x + offset.x, shrek.position.y + offset.y, transform.position.z);
        }
        else
        {
            transform.position = new Vector3(shrek.position.x - offset.x, shrek.position.y + offset.y, transform.position.z);
        }
    }

    void Update()
    {
        if (pauseMenu.activeInHierarchy == false && deathMenu.activeInHierarchy == false && finishMenu.activeInHierarchy == false)
        {
            Cursor.visible = false;
        }
        else
        {
            Cursor.visible = true;
        }

        if (shrek)
        {
            int currentX = Mathf.RoundToInt(shrek.position.x);
            if (currentX > lastX)
            {
                faceRight = true;
            }
            else if (currentX < lastX)
            {
                faceRight = false;
            }
            lastX = Mathf.RoundToInt(shrek.position.x);
            Vector3 target;
            if (faceRight)
            {
                target = new Vector3(shrek.position.x + offset.x, shrek.position.y + offset.y, transform.position.z);
            }
            else
            {
                target = new Vector3(shrek.position.x - offset.x, shrek.position.y + offset.y, transform.position.z);
            }
            Vector3 currentPosition = Vector3.Lerp(transform.position, target, damping * Time.deltaTime);
            Borders(ref currentPosition);
            transform.position = currentPosition;
        }
    }

    void Borders(ref Vector3 pos)
    {
        if (pos.x < 4.45f)
        {
            pos.x = 4.45f;
        }
        if (pos.y < -2f)
        {
            pos.y = 2f;
        }
        if (pos.y > 1.7f)
        {
            pos.y = 1.7f;
        }
    }
}